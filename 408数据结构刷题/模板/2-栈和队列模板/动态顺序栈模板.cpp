#include <bits/stdc++.h>
using namespace std;

// ==========================================
// 动态顺序栈（考研 408 / 书本实现形式二：双指针模型）
// 保持 C++ 语法风格：引用传递 &、new/delete[] 内存管理
// ==========================================

// bottom: 栈底指针（指向动态分配数组的首地址）
// top:    栈顶指针，始终指向“当前栈顶元素的下一个空位”（初始化时 top == bottom）
// stacksize: 当前栈已分配的容量上限（元素个数）
struct SqStack
{
    int* bottom;   // 栈底指针
    int* top;      // 栈顶指针（注意：由下标改为指针类型）
    int stacksize; // 当前分配的容量大小
};

// 1. 初始化
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool InitStack(SqStack &S, int initialCapacity = 4)
{
    if (initialCapacity <= 0) return false;

    S.bottom = new(nothrow) int[initialCapacity];
    if (S.bottom == nullptr) return false;

    S.top = S.bottom;             // 核心点：空栈时 top == bottom
    S.stacksize = initialCapacity;
    return true;
}

// 2. 判空
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool StackEmpty(const SqStack &S)
{
    return S.top == S.bottom;     // 核心点：栈顶与栈底重合即为空
}

// 3. 栈长（元素个数）
// 时间复杂度: O(1)
// 空间复杂度: O(1)
int StackLength(const SqStack &S)
{
    return S.top - S.bottom;      // 指针相减得到当前元素个数
}

// 4. 扩容：容量扩大为原来的两倍
// 时间复杂度: O(n)（需要迁移复制已有元素）
// 空间复杂度: O(n)（申请 2n 容量的新连续内存）
bool GrowStack(SqStack &S)
{
    if (S.stacksize > INT_MAX / 2) return false;
    int newCapacity = S.stacksize * 2;

    int* newBottom = new(nothrow) int[newCapacity];
    if (newBottom == nullptr) return false;

    // 计算当前已有元素个数
    int currentLen = S.top - S.bottom;

    // 复制原栈中的有效元素
    for (int i = 0; i < currentLen; i++)
    {
        newBottom[i] = S.bottom[i];
    }

    delete[] S.bottom;

    // 核心点：更新基地址后，必须重新定位 top 指针！
    S.bottom = newBottom;
    S.top = S.bottom + currentLen;
    S.stacksize = newCapacity;

    return true;
}

// 5. 进栈
// 时间复杂度: 均摊 O(1)，触发扩容时最坏 O(n)
// 空间复杂度: O(1)，扩容时辅助空间 O(n)
bool Push(SqStack &S, int x)
{
    // 外层 if 判满：指针差值达到容量上限时扩容
    if (S.top - S.bottom >= S.stacksize)
    {
        bool isOK = GrowStack(S);
        if (isOK == false)
        {
            return false; // 扩容失败直接返回
        }
    }
    // 正常存入元素，栈顶后移
    *S.top++ = x; // 将 x 赋值给当前 top，栈顶后移
    return true;
}

// 6. 出栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool Pop(SqStack &S, int &x)
{
    if (StackEmpty(S)) return false;
    x = *--S.top; // 核心点：top 先自减 1 指向实际栈顶元素，再解引用取值
    return true;
}

// 7. 读取栈顶元素
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool GetTop(const SqStack &S, int &x)
{
    if (StackEmpty(S)) return false;
    x = *(S.top - 1); // 核心点：top 指向下一个空位，栈顶元素在 top - 1
    return true;
}

// 8. 销毁栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
void DestroyStack(SqStack &S)
{
    delete[] S.bottom;
    S.bottom = nullptr;
    S.top = nullptr;
    S.stacksize = 0;
}

// ==========================================
// ACM 模式测试
// ==========================================
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SqStack S;
    if (!InitStack(S, 2)) // 初始容量设为 2，方便测试自动扩容
    {
        cout << "Init Failed\n";
        return 0;
    }

    // 测试压栈与动态扩容
    for (int i = 1; i <= 5; i++)
    {
        Push(S, i * 10);
        cout << "Push " << i * 10 << " | Current Length: " << StackLength(S) << "\n";
    }

    // 测试取栈顶
    int topVal;
    if (GetTop(S, topVal))
    {
        cout << "Top element is: " << topVal << "\n";
    }

    // 测试弹栈
    cout << "Popping elements: ";
    int val;
    while (!StackEmpty(S))
    {
        Pop(S, val);
        cout << val << " ";
    }
    cout << "\n";

    DestroyStack(S);
    return 0;
}
