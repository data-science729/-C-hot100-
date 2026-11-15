/**
 * 题目名称：合并有序链表
 * 
 * 【题目描述】
 * 给定两个按非递减顺序排列的单链表，将它们的全部节点合并为一个新的非递减链表。
 * 
 * 【输入格式】
 * 第一行输入整数 n，第二行输入 n 个整数，按从头到尾的顺序表示第一个链表；当 n = 0 时第二行为空。
 * 第三行输入整数 m，第四行输入 m 个整数，按从头到尾的顺序表示第二个链表；当 m = 0 时第四行为空。
 * 
 * 【输出格式】
 * 第一行输出合并后链表的节点数。
 * 若链表非空，第二行按从头到尾的顺序输出各节点值；若链表为空，则不再输出第二行。
 * 
 * 【数据范围】
 * - 0 <= n, m <= 50
 * - -100 <= 节点值 <= 100
 * - 两个输入链表均按非递减顺序排列
 * 
 * 【输入样例】
 * 3
 * 1 2 4
 * 3
 * 1 3 4
 * 
 * 【输出样例】
 * 6
 * 1 1 2 3 4 4
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

//拉链法
 //给定两个按非递减顺序排列的单链表，将它们的全部节点合并为一个新的非递减链表。
ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
{
  //不想用冗长的if-else判断list1 list2谁开头更小 用上dummy
  ListNode dummy(0);
  ListNode* tail = &dummy;
  //比大小 谁小拉谁
  while(list1!=nullptr && list2!=nullptr)
  {
    if(list1->val<=list2->val)
    {
        tail->next = list1; //1班更小接1班的人
        list1 = list1->next ; //1班队伍向前迈一步
    }
    else
    {
      tail->next = list2;
      list2 = list2->next;
    }
    tail = tail->next ; //新链表尾指针后移
  }
   //当while退出时 说明至少有一条链表已经空了
 //链表剩下的那一段本身就已经相互连好 并且已经有序
if(list1!=nullptr)
{
    tail->next = list1;
}
else
{
    tail->next = list2;
}
return dummy.next;
}


void solve(int n)
{
    //1.读入第一条链表的n个数据(若n=0则vector为空)
    vector<int> nums1(n);
    for(int i = 0;i<n;i++)
    {
        cin>>nums1[i];
    }
    //2.紧接着读入m和第二条链表的m个数据
    int m;
    vector<int> nums2(m);
    for(int i =0;i<m;i++)
    {
        cin>>nums2[i];
    }
    //3.用模板分别建立两条真实链表
    ListNode* list1 = buildList(nums1);
    ListNode* list2 = buildList(nums2);

    //4.调用核心算法
    ListNode* head = mergeTwoLists(list1,list2);
    
    //5.处理输出要求
    //第一行 输出合并后的总节点数(m+n)
    cout<<(m+n)<<'\n';
    //第二行 若链表非空(m+n>0) 输出节点的值
    if(m+n>0)
    {
        printList(head);
    }
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


