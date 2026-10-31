
#include <bits/stdc++.h>
using namespace std;

//==================== 十字链表结点 ====================

struct OLNode {
    int row, col;       // 当前非零元素的行号、列号
    int value;          // 当前非零元素的值

    OLNode* right;      // 指向同一行的下一个非零元素
    OLNode* down;       // 指向同一列的下一个非零元素

    OLNode(int r, int c, int v)
        : row(r), col(c), value(v),
          right(nullptr), down(nullptr) {}
};

//==================== 十字链表整体结构 ====================

struct CrossList {
    int rows, cols;     // 矩阵的行数、列数
    int nums;           // 非零元素个数

    OLNode** rhead;     // 行头指针数组
    OLNode** chead;     // 列头指针数组
};

//==================== 初始化十字链表 ====================

// triples 中每个元素为 {行号, 列号, 元素值}
// 要求坐标合法且没有重复坐标
// 最终按照行号、列号递增的顺序建立链表
bool CreateCrossList(CrossList& M, int m, int n,
                     vector<array<int, 3>> triples)
{
    M.rows = m;
    M.cols = n;
    M.nums = 0;

    // 分配行头指针数组，行号从 1 开始使用
    M.rhead = new OLNode*[m + 1]();

    // 分配列头指针数组，列号从 1 开始使用
    M.chead = new OLNode*[n + 1]();

    // 按照行号、列号递增排序
    sort(triples.begin(), triples.end());

    // 辅助指针数组：记录每一行、每一列当前的尾结点
    vector<OLNode*> rtail(m + 1, nullptr);
    vector<OLNode*> ctail(n + 1, nullptr);

    for (auto t : triples) {
        int r = t[0];
        int c = t[1];
        int v = t[2];

        // 检查坐标是否合法
        if (r < 1 || r > m || c < 1 || c > n || v == 0) {
            DestroyCrossList(M);
            return false;
        }

        // 不允许同一个位置重复出现
        if (M.nums > 0) {
            auto last = triples[M.nums - 1];
            if (last[0] == r && last[1] == c) {
                DestroyCrossList(M);
                return false;
            }
        }

        // 创建一个非零元素结点
        OLNode* p = new OLNode(r, c, v);

        //---------- 接入行链表 ----------

        if (M.rhead[r] == nullptr) {
            // 当前行还没有结点
            // p 成为该行的第一个结点
            M.rhead[r] = p;
        }
        else {
            // 将 p 接到当前行尾结点后面
            rtail[r]->right = p;
        }

        // 更新当前行尾结点
        rtail[r] = p;

        //---------- 接入列链表 ----------

        if (M.chead[c] == nullptr) {
            // 当前列还没有结点
            // p 成为该列的第一个结点
            M.chead[c] = p;
        }
        else {
            // 将 p 接到当前列尾结点后面
            ctail[c]->down = p;
        }

        // 更新当前列尾结点
        ctail[c] = p;

        M.nums++;
    }

    return true;
}

//==================== 按行遍历 ====================

void PrintByRow(const CrossList& M)
{
    for (int i = 1; i <= M.rows; i++) {
        cout << "第 " << i << " 行: ";

        OLNode* p = M.rhead[i];

        while (p != nullptr) {
            cout << "(" << p->row << ","
                 << p->col << "," << p->value << ") ";

            // 沿着同一行向右移动
            p = p->right;
        }

        cout << '\n';
    }
}

//==================== 按列遍历 ====================

void PrintByCol(const CrossList& M)
{
    for (int j = 1; j <= M.cols; j++) {
        cout << "第 " << j << " 列: ";

        OLNode* p = M.chead[j];

        while (p != nullptr) {
            cout << "(" << p->row << ","
                 << p->col << "," << p->value << ") ";

            // 沿着同一列向下移动
            p = p->down;
        }

        cout << '\n';
    }
}

//==================== 查找指定位置元素 ====================

// 查找矩阵 A[i][j]，没有非零元素则返回 0
int GetValue(const CrossList& M, int i, int j)
{
    if (i < 1 || i > M.rows ||
        j < 1 || j > M.cols) {
        return 0;
    }

    // 只需要遍历第 i 行
    OLNode* p = M.rhead[i];

    while (p != nullptr && p->col < j) {
        p = p->right;
    }

    if (p != nullptr && p->col == j) {
        return p->value;
    }

    return 0;
}

//==================== 销毁十字链表 ====================

void DestroyCrossList(CrossList& M)
{
    // 沿行链表遍历并释放结点
    // 每个结点只释放一次，不能再沿列链表释放
    for (int i = 1; i <= M.rows; i++) {
        OLNode* p = M.rhead[i];

        while (p != nullptr) {
            OLNode* q = p->right;
            delete p;
            p = q;
        }
    }

    // 释放行、列头指针数组
    delete[] M.rhead;
    delete[] M.chead;

    M.rhead = nullptr;
    M.chead = nullptr;
    M.rows = M.cols = M.nums = 0;
}

//==================== 测试 ====================

int main()
{
    CrossList M{};

    // 三元组：{行号, 列号, 元素值}
    vector<array<int, 3>> triples = {
        {1, 3, 5},
        {2, 2, 8},
        {3, 4, 3},
        {4, 1, 6}
    };

    if (!CreateCrossList(M, 4, 4, triples)) {
        cout << "创建失败\n";
        return 0;
    }

    cout << "按行遍历：\n";
    PrintByRow(M);

    cout << "\n按列遍历：\n";
    PrintByCol(M);

    cout << "\nA[2][2] = " << GetValue(M, 2, 2);
    cout << "\nA[1][1] = " << GetValue(M, 1, 1) << '\n';

    DestroyCrossList(M);

    return 0;
}
