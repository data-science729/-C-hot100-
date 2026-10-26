#include <bits/stdc++.h>
using namespace std;

// 1. 定义单链表节点
struct ListNode {
    int val;         // 当前节点存储的数据
    ListNode* next;  // 指向下一个节点的指针 定义变量类型时 *是指针类型修饰符 
                     //表示next是一个存地址的指针变量

    // 构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

// 2. 根据数组构建链表（尾插法）
ListNode* buildList(const vector<int>& nums) {
    ListNode dummy(0);      // 栈上虚拟头节点，不用 new，函数结束后自动释放
    ListNode* tail = &dummy; // 尾指针，初始指向 dummy

    for(int i = 0;i<nums.size();++i)
    {
        int x = nums[i];
        tail->next = new ListNode(x); //创建新节点并拼到尾部
        tail = tail->next; //尾指针后移
    }
    return dummy.next;      //卸磨杀驴，扔掉了临时的dummy,把真正第一个有效节点的地址交付给外部 返回实际头节点指针
}

// 3. 遍历并输出链表
void printList(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) {
        cout << p->val;
        // 关键修正：必须是 if，不是 while！非末尾节点输出空格分隔
        if (p->next != nullptr) {
            cout << " ";
        }
        p = p->next;
    }
    cout << '\n';
}

// 4. 释放链表的动态内存
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head; // 暂存当前要删的节点
        head = head->next;     // head 提前后移到安全位置
        delete temp;           // 释放暂存节点
    }
}

// 5. ACM 模式测试入口
int main() {
    // 快速 I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // 多组测试输入：先读入数组大小 n，再读入 n 个整数
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        // 构建 -> 打印 -> 释放
        ListNode* head = buildList(nums);
        printList(head);
        deleteList(head);
    }

    return 0;
}