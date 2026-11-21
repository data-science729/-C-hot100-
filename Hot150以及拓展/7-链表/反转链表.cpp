/**
 * 题目名称：反转链表
 * 来源：力扣 Hot 100 / 考研机试真题
 *
 * 题目描述：
 * 给定一个单链表，反转所有下一指针，使原链尾成为新链首，并输出反转后的链表。
 *
 * 输入格式：
 * 第一行输入整数 n，表示链表结点数。
 * 若 n > 0，第二行按从链首到链尾的顺序输入 n 个整数，表示各结点的值。
 * 相邻输入值对应的结点由下一指针连接，最后一个结点的下一指针为空。
 *
 * 输出格式：
 * 第一行输出反转后链表的结点数 n。
 * 若 n > 0，第二行按从新链首到新链尾的顺序输出 n 个结点值，相邻值用一个空格分隔。
 *
 * 数据范围：
 * 0 <= n <= 5000
 * -5000 <= Node.val <= 5000
 *
 * 输入样例：
 * 5
 * 1 2 3 4 5
 *
 * 输出样例：
 * 5
 * 5 4 3 2 1
 */

 //思路:让每个节点的next指向原来的前驱节点
#include<bits/stdc++.h>
using namespace std;

//先背模板
struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x,ListNode* next):val(x),next(next) {}
};

ListNode* buildList(const vector<int>& nums)
{
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for(int i = 0;i<nums.size();++i)
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
        //只要不是最后一个节点 需要空格分隔
        if(p->next!=nullptr)
        {
         cout<<" ";
        }
        p = p->next;
    }
    cout<<'\n';
}

void deleteList(ListNode* head)
{
    while(head!=nullptr)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

//reverseList()必须返回新的头节点
//三指针迭代法
ListNode* reverseList(ListNode* head)
{
    //ListNode* node = nullptr 表示:创建一个节点node,让它暂时不指向任何节点
    //node->next = nullptr 表示:找到node所指向的节点，把这个节点的next修改为nullptr
    //1.定义好三个指针
   ListNode* prev = nullptr;  //已反转部分的头节点
   ListNode* curr = head;   //当前正在处理的节点
   ListNode* next = nullptr;  //暂存当前节点原来的后继节点
   while(curr!=nullptr)
   {
      next = curr->next; //先暂存后继节点
      curr->next = prev;  //反转当前节点的指针
      prev = curr; //prev指针前进一步
      curr = next ; //curr指针前进一步
   }
   return prev;  //prev最终停留在新链表的头节点
}

void solve(int n)
{
   
    cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];       
    }
    ListNode* head = buildList(nums);
    head = reverseList(head);
    //第一行输出反转后链表的结点数n
    cout<<n<<'\n';
    //若n>0 第二行输出各结点值
    if(n>0)
    {
        printList(head);
    }
    deleteList(head);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n;
   while(cin>>n)
   {
    solve(n);
   }
   return 0;
}