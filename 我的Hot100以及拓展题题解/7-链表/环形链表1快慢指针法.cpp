/**
 * 题目名称：141. 环形链表 (Linked List Cycle)
 * 
 * 【题目描述】
 * 给你一个链表的头节点 head，判断链表中是否有环。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 * 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 注意：pos 不作为核心算法函数的参数传递，此处在 ACM 模式下用于构建测试用例链表。
 * 如果链表中存在环，则输出 true；否则，输出 false。
 * 
 * 【输入格式】
 * 第一行输入两个整数 n 和 pos，分别表示链表节点的数目以及链表尾节点指向的节点索引（索引从 0 开始，若为 -1 则表示无环）。
 * 第二行输入 n 个整数，按顺序表示链表各节点的值 val；若 n = 0，则第二行为空。
 * 
 * 【输出格式】
 * 若链表中存在环，输出 "true"；否则输出 "false"。
 * 
 * 【数据范围】
 * - 0 <= n <= 10^4
 * - -10^5 <= val <= 10^5
 * - pos 为 -1 或 [0, n - 1] 范围内的有效索引
 * 
 * 【进阶要求】
 * 使用 O(1)（即常量级别）额外内存空间解决此问题（双指针 / 快慢指针法）。
 * 
 * 【输入样例 1】
 * 4 1
 * 3 2 0 -4
 * 
 * 【输出样例 1】
 * true
 * 
 * 【输入样例 2】
 * 2 0
 * 1 2
 * 
 * 【输出样例 2】
 * true
 * 
 * 【输入样例 3】
 * 1 -1
 * 1
 * 
 * 【输出样例 3】
 * false
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x,ListNode* nextNode):val(x),next(nextNode) {}
};

ListNode* buildList(const vector<int>& nums)
{
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for(int i = 0;i<nums.size();i++)
    {
        int x = nums[i];
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}
void printList(ListNode* head)
{
    ListNode* p = head;
    while(p!=nullptr)
    {
        cout<<p->val;
        if(p->next!=nullptr)
        {
            cout<<" ";
        }
        p = p->next;
    }
    cout<<'\n';
}

bool hasCycle(ListNode* head)
{
    //1.两个指针均从头节点出发
    ListNode* slow = head;
    ListNode* fast = head;
    //2.循环条件:由于后面要访问fast->next->next
    //因此fast不能是空指针 且fast->next也不能是空指针
    while(fast!=nullptr && fast->next!=nullptr)
    {
    //3.移动指针
    slow = slow->next; //慢指针走一步
    fast = fast->next->next; // 快指针走两步
    if(slow == fast)
    {
        return true; //两指针相遇 存在环
    }
    }
    return false; //快指针达到末尾 不存在环
}

//ACM模式下 solve中要加入造环逻辑！！
void solve(int n,int pos)
{
  
  vector<int> nums(n);
  for(int i = 0;i<n;i++)
  {
    cin>>nums[i];
  }
  ListNode* head = buildList(nums);
  //根据pos手动把尾节点连回入环点
  if(pos!=-1 && head!=nullptr)
  {
    ListNode* tail = head; //尾节点
    ListNode* entry = nullptr; //入环点
    int idx = 0;
    //找到入环点entry和尾节点tail
    while(tail!=nullptr)
    {
        if(idx == pos)  entry = tail;
        if(tail->next == nullptr)  break; //停在最后一个节点
        tail = tail->next;
        idx++;
    }
    //尾节点指向入环点 正式成环
    tail->next = entry;
  }
  bool flag = hasCycle(head);
  cout<<(flag?"true":"false")<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,pos;
    while(cin>>n>>pos)
    {
        solve(n,pos);
    }
    return 0;
}