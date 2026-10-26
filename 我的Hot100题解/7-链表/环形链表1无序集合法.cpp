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

bool hasCycle(ListNode* head)
{
    //容器类型<存放的元素类型> 变量名
    unordered_set<ListNode*> visited;
    ListNode* curr = head;
    while(curr!=nullptr)
    {
        //当前节点地址已经出现过 说明存在环
        if(visited.count(curr))
        {
          return true;
        }
        //记录当前节点地址放入无序集合|
        visited.insert(curr);
        //继续访问下一个节点
        curr = curr->next;
    }
    //如果遍历到了nullptr 说明不存在环
    return false;
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