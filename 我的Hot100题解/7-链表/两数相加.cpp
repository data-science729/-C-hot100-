/**
 * 题目名称：两数相加
 * 来源：力扣hot100 / 考研机试真题
 * 
 * 题目描述：
 * 两个非空链表分别表示两个非负整数，每个节点存储一位数字，数字按从低位到高位的顺序排列。
 * 求两数之和，并按同样的逆序形式输出结果链表。
 * 除数字 0 外，输入表示的整数没有前导零。
 * 
 * 输入格式：
 * 第一行输入整数 n，第二行输入 n 个整数，依次表示第一个链表从头到尾的节点值。
 * 第三行输入整数 m，第四行输入 m 个整数，依次表示第二个链表从头到尾的节点值。
 * 
 * 输出格式：
 * 第一行输出结果链表的节点数。
 * 第二行按从头到尾的顺序输出各节点值，中间用一个空格分隔。
 * 
 * 数据范围：
 * 1 <= n, m <= 100
 * 0 <= 节点值 <= 9
 * 除单个节点 0 外，每个链表的最后一个节点值非零。
 * 
 * 输入样例：
 * 3
 * 2 4 3  -->342
 * 3
 * 5 6 4  -->465
 *    不需要额外逆序 因为输入本身已经是低位在前
 * 输出样例：
 * 3
 * 7 0 8  -->807
 */

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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

//辅助函数：统计链表长度(因为第一行要输出节点数)
int getlength(ListNode* head)
{
    int len = 0 ;
    while(head != nullptr)
    {
        len++;
        head = head->next;
    }
    return len; 
}

ListNode* addtwonumbers(ListNode* l1,ListNode* l2)
{
   //1.创建虚拟头节点和尾指针
   ListNode dummy(0);
   ListNode* tail = &dummy;
   //2.初始化进位
   int carry = 0;
   //3.遍历两个链表
   while(l1 != nullptr || l2!=nullptr || carry)
   {
    //取出当前数位 不存在的数位按0处理
    int x = (l1 != nullptr) ? l1->val : 0;
    int y = (l2 != nullptr) ? l2->val : 0;
    //核心加法
    int t = x + y + carry;
    carry = t / 10;
    int digit = t % 10;
    //创建节点并连接 尾插法标准写法 熟记
    tail->next = new ListNode(digit);
    tail = tail->next;
    //指针链表后移
    if(l1 != nullptr)  l1 = l1->next;
    if(l2 != nullptr)  l2 = l2->next;
   }
   return dummy.next;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    //多组输入循环:只要能读到第一行的n 就说明有一组新测试用例
    while(cin>>n)
    {
        // 读入第一个链表
        vector<int> nums1(n);
        for(int i = 0 ; i<n;i++)
        {
            cin>>nums1[i];
        }
        //读入第二个链表
        int m ;
        cin>>m;
        vector<int> nums2(m);
        for(int i = 0 ;i<m;i++)
        {
            cin>>nums2[i];
        }

        // 将俩vector构造成题目要求的链表
        ListNode* l1 = buildList(nums1);
        ListNode* l2 = buildList(nums2);

        //核心计算
        ListNode* res = addtwonumbers(l1,l2);

        //格式化输出:第一行输出节点数 第二行输出各节点值
        cout<<getlength(res)<<"\n";
        printList(res);
    }
    return 0;
}
