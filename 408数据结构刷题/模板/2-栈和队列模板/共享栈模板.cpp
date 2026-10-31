#include <bits/stdc++.h>
using namespace std;

// ==========================================
// 共享栈（对顶栈）
// 核心思想：利用数组两端向中间延伸，提高空间利用率
// 指针定义：t1、t2 分别指向栈1和栈2“即将插入的下一个空位”
// ==========================================

const int MaxSize = 100;

struct SharedStack
{
    int data[MaxSize];

    int b1;  // 栈1栈底，固定为0
    int t1;  // 栈1栈顶指针，指向下一个空位（初始化为0）

    int t2;  // 栈2栈顶指针，指向下一个空位（初始化为MaxSize-1）
    int b2;  // 栈2栈底，固定为MaxSize-1
};

// 1. 初始化
// 时间复杂度: O(1)
// 空间复杂度: O(1)
void InitStack(SharedStack &S)
{
    S.b1 = S.t1 = 0;
    S.b2 = S.t2 = MaxSize - 1;
}

// 2. 判空
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool StackEmpty(const SharedStack &S, int stackNo)
{
    if (stackNo == 1) return S.t1 == S.b1;
    if (stackNo == 2) return S.t2 == S.b2;

    return false;
}

// 3. 判满
// 时间复杂度: O(1)
// 空间复杂度: O(1)
// 【BUG修复说明】：
// 指针 t1 和 t2 指向的是“下一个空位”。
// 当 t1 == t2 时，数组中仍有 1 个空位可供任一栈插入。
// 当且仅当 t1 > t2（即 t1 - t2 == 1）时，两端指针完全交错，所有空位耗尽，栈满。
// 原代码误写为 S.t2 - S.t1 == 1，会导致浪费 2 个可用空间提前误判为满。
bool StackFull(const SharedStack &S)
{
    return S.t1 > S.t2;
}

// 4. 求栈长
// 时间复杂度: O(1)
// 空间复杂度: O(1)
int StackLength(const SharedStack &S, int stackNo)
{
    if (stackNo == 1) return S.t1 - S.b1;
    if (stackNo == 2) return S.b2 - S.t2;

    return -1;
}

// 5. 入栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool Push(SharedStack &S, int x, int stackNo)
{
    if (StackFull(S)) return false; // 栈满不可插入

    if (stackNo == 1)
    {
        S.data[S.t1++] = x;
    }
    else if (stackNo == 2)
    {
        S.data[S.t2--] = x;
    }
    else
    {
        return false;
    }

    return true;
}

// 6. 出栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool Pop(SharedStack &S, int &x, int stackNo)
{
    if (StackEmpty(S, stackNo)) return false; // 栈空不可弹出

    if (stackNo == 1)
    {
        x = S.data[--S.t1];
    }
    else if (stackNo == 2)
    {
        x = S.data[++S.t2];
    }
    else
    {
        return false;
    }

    return true;
}

// 7. 读取栈顶
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool GetTop(const SharedStack &S, int &x, int stackNo)
{
    if (StackEmpty(S, stackNo)) return false;

    if (stackNo == 1)
    {
        x = S.data[S.t1 - 1];
    }
    else if (stackNo == 2)
    {
        x = S.data[S.t2 + 1];
    }
    else
    {
        return false;
    }

    return true;
}

// ==========================================
// ACM 模式测试
// ==========================================
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SharedStack S;
    InitStack(S);

    // 测试两端分别入栈
    Push(S, 10, 1);
    Push(S, 20, 1);
    Push(S, 99, 2);
    Push(S, 88, 2);

    cout << "Stack 1 Length: " << StackLength(S, 1) << "\n";
    cout << "Stack 2 Length: " << StackLength(S, 2) << "\n";

    int top1, top2;
    if (GetTop(S, top1, 1)) cout << "Stack 1 Top: " << top1 << "\n";
    if (GetTop(S, top2, 2)) cout << "Stack 2 Top: " << top2 << "\n";

    // 测试出栈
    int val;
    cout << "Stack 1 Pop: ";
    while (!StackEmpty(S, 1))
    {
        Pop(S, val, 1);
        cout << val << " ";
    }
    cout << "\n";

    cout << "Stack 2 Pop: ";
    while (!StackEmpty(S, 2))
    {
        Pop(S, val, 2);
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
