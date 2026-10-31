#include <bits/stdc++.h>
using namespace std;

// ==========================================
// 链栈（带头结点）: 本质是"仅在表头进行插入和删除的单链表" "头出头插"
// 核心思想：单链表头插法压栈，首元结点出栈，无容量上限限制
// ==========================================

// 链栈结点
struct StackNode
{
    int data;
    StackNode* next;
    StackNode(int x = 0) : data(x), next(nullptr) {}
};

// 带头结点的链栈
struct LinkStack
{
    StackNode* head; // 头结点指针
    int length;      // 栈中有效元素的个数
};

// 1. 初始化: 动态申请头结点
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool InitStack(LinkStack &S)
{
    S.head = new(nothrow) StackNode;
    if (S.head == nullptr) return false;
    S.head->next = nullptr;
    S.length = 0;
    return true;
}

// 2. 判空
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool StackEmpty(const LinkStack &S)
{
    return S.head == nullptr || S.head->next == nullptr;
}

// 3. 求栈长
// 时间复杂度: O(1)
// 空间复杂度: O(1)
int StackLength(const LinkStack &S)
{
    return S.length;
}

// 4. 入栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool Push(LinkStack &S, int x)
{
    if (S.head == nullptr) return false;
    StackNode* s = new(nothrow) StackNode(x);
    if (s == nullptr) return false;

    // 头插法: 先接后面，再接前面
    s->next = S.head->next;
    S.head->next = s;
    S.length++;
    return true;
}

// 5. 出栈
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool Pop(LinkStack &S, int &x)
{
    if (StackEmpty(S)) return false;

    StackNode* p = S.head->next;
    x = p->data;
    S.head->next = p->next;
    delete p;
    S.length--;
    return true;
}

// 6. 读取栈顶数据
// 时间复杂度: O(1)
// 空间复杂度: O(1)
bool GetTop(const LinkStack &S, int &x)
{
    if (StackEmpty(S)) return false;
    x = S.head->next->data;
    return true;
}

// 7. 销毁栈
// 时间复杂度: O(n)（需要逐个释放每个结点）
// 空间复杂度: O(1)
void DestroyStack(LinkStack &S)
{
    if (S.head == nullptr) return;

    StackNode* p = S.head;
    while (p != nullptr)
    {
        StackNode* temp = p;
        p = p->next;
        delete temp;
    }
    S.head = nullptr;
    S.length = 0;
}

// ==========================================
// ACM 模式测试
// ==========================================
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LinkStack S;
    if (!InitStack(S))
    {
        cout << "Init Failed\n";
        return 0;
    }

    // 测试连续入栈
    for (int i = 1; i <= 5; i++)
    {
        Push(S, i * 10);
        cout << "Push: " << i * 10 << " | Current Length: " << StackLength(S) << "\n";
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

    DestroyStack(S);
    return 0;
}
