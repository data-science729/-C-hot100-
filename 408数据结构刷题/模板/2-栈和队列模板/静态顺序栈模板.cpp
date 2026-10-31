#include <bits/stdc++.h>
using namespace std;

// ==========================================
// 静态顺序栈（考研 408 实现形式二：top 初始化在有效位置）
// 特点：S.top 始终指向“当前栈顶元素的下一个空位”（即即将插入的位置）
// 空栈时 top = 0，0 是数组的有效下标（即所谓“初始化的位置是有效的位置”）
// ==========================================

const int MaxSize = 1000;

struct SqStack
{
    int data[MaxSize];
    int top; // 栈顶指针（下标）：指向下一个可用位置，空栈时 top = 0
    SqStack() : top(0) {}
};

// 1. 初始化
// 时间复杂度: O(1)
// 空间复杂度: O(1)
void InitStack(SqStack &S)
{
    S.top = 0; // top 赋值为 0（有效位置），表示当前无元素，下一个插入位置为下标 0
}

// 2. 判空
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool StackEmpty(const SqStack &S)
{
    return S.top == 0; // top 为 0 时表示栈空
}

// 3. 判满
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool StackFull(const SqStack &S)
{
    return S.top == MaxSize; // top 达到 MaxSize 表示栈已满
}

// 4. 获取栈长（当前元素个数）
// 时间复杂度: O(1)
// 空间复杂度: O(1)
int StackLength(const SqStack &S)
{
    return S.top; // top 的值正好等于当前栈内的元素个数
}

// 5. 入栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool Push(SqStack &S, int x)
{
    if (StackFull(S)) return false; // 栈满则报错
    S.data[S.top++] = x;            // 核心：先将 x 存入当前有效下标 top，然后 top 自增 1
    return true;
}

// 6. 出栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool Pop(SqStack &S, int &x)
{
    if (StackEmpty(S)) return false; // 栈空则报错
    x = S.data[--S.top];             // 核心：top 当前指向空位，先自减 1 指向真实栈顶元素，再取值
    return true;
}

// 7. 读取栈顶元素
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool GetTop(const SqStack &S, int &x)
{
    if (StackEmpty(S)) return false; // 栈空则报错
    x = S.data[S.top - 1];           // 核心：top 指向空位，真正栈顶在 top - 1，不改变 top 的值
    return true;
}

// ==========================================
// ACM 模式测试
// ==========================================
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SqStack S;
    InitStack(S);

    // 测试连续入栈
    for (int i = 1; i <= 5; i++)
    {
        Push(S, i * 100);
        cout << "Push: " << i * 100 << " | Current Length: " << StackLength(S) << "\n";
    }

    // 测试读取栈顶
    int topVal;
    if (GetTop(S, topVal))
    {
        cout << "Top element is: " << topVal << "\n";
    }

    // 测试连续出栈
    cout << "Popping elements: ";
    int val;
    while (!StackEmpty(S))
    {
        Pop(S, val);
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
