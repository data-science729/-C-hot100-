#include <bits/stdc++.h>
using namespace std;

// 1. 定义单链表结点
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {} //初值0 next为nullptr

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* nextNode)
        : val(x), next(nextNode) {}
};

//2.创建带头结点的空链表O(1)
//作用 只要我们 ListNode* head = InitList() 就有head->[0|nullptr] (本身指向dummy)
//head叫"头指针" 它本身不是结点 它只存储一个内存地址
//dummy是通过new出来的完整结点对象叫"头/哑结点"[0|nullptr]
//空表时head->next指向的是dummy中的nullptr
//写入了元素a1时 dummy的next字段被覆写为a1的结点地址 
//这时head->next 是address(a1)
ListNode* InitList()
{
    return new ListNode(); //永久存在的虚拟头结点 无值
}

//3.判断链表是否为空O(1)
bool Empty(ListNode* head)
{
    return head->next == nullptr;
}

//4.求表长 O(n)
int Length(ListNode* head)
{
    int len = 0;
    ListNode* p = head->next ; //head是sentinel head->next才相当于第0个元素
    while(p!=nullptr)
    {
       len++;
       p = p->next;
    }
    return len;
}

//5.按位查找:返回第i个数据结点 O(n)
//需要支持能定位到第0个结点，因为后续插入删除要找第1个结点前驱
ListNode* GetElem(ListNode* head,int i)
{
    if(i<0)  return nullptr;
    ListNode* p = head; //按位查找 我们也可能说要看i=0:[0|nullptr的]
    int j = 0;  //计时器j设为0 代表p当前停在0号头结点的位置
    while(p!=nullptr && j<i)  //循环前进 只要没走到末尾且步数未达到i
    { 
        p = p->next;  //p往后走一步
        j++;   //计数器同步加1
    }
    return p;  //返回查找到的结点指针
}

//6.按值查找:返回第一个值为e的结点 O(n)
//按值查找我们只比对有效数据的 因而p = head->next
ListNode* LocateElem(ListNode* head,int e)
{
    ListNode* p = head->next; 
    while(p!=nullptr)
    {
       if(p->val == e)
       {
        return p;
       }
       p = p->next;
    }
    //找遍全表都没找到 返回空指针
    return nullptr;
}

//7.按位插入:在第i个位置插入元素e O(n)
//若要建整个表 每次O(n) 要O(n^2) 用头插法尾插法优化
bool ListInsert(ListNode* head,int i,int e)
{
    //禁止在逻辑上的非有效位置(哑结点以及之前)
    if(i<1)  return false;
    //找到第i-1个节点
    ListNode* p = GetElem(head,i-1);
    //拦截越界位置
    if(p == nullptr)  return false;
    //创造新结点 并连接后继
    ListNode* s = new ListNode(e,p->next);
    //修改前驱结点的指针域 指向新节点
    p->next = s;
    return true;
}

//8.按位删除:删除第i个数据结点 O(n)
bool ListDelete(ListNode* head,int i,int& e)
{
    if(i<1)  return false;
    ListNode* p = GetElem(head,i-1);
    if(p==nullptr || p->next==nullptr)
    {
        return false;
    }
    ListNode* q = p->next;
    e = q->val;
    p->next = q->next;  //绕过q 把前驱连接到后继
    delete q;
    return true;
}

//9.遍历输出链表 O(n)
void PrintList(ListNode* head)
{
    ListNode* p = head->next;
    while(p!=nullptr)
    {
        cout<<p->val;
        if(p->next!=nullptr)
        {
            cout<<' ';
        }
        p = p->next;
    }
    cout<<'\n';
}

//10.释放全部结点(包括头结点) O(n)
void DestroyList(ListNode* head)
{
     while(head!=nullptr)
     {
         ListNode* temp = head;
         head = head->next;
         delete temp;
     }
}

//====================进阶===================//
//这是"复制数据"技巧 无法"保持物理结点身份"
//11.头插法建立单链表:每读入一个元素 就把它插入头结点之后
//如 10 20 30
//变head->[dummy]->30->20->10->nullptr 会逆置输入顺序
ListNode* List_HeadInsert(int n)
{
   //初始化链表 创建头结点
   ListNode* head = InitList();
   //循环读入并插入n个元素
   for(int i = 0;i<n;i++)
   {
       int x; 
       cin>>x;
       ListNode* s = new ListNode(x);
       //新结点指向原来的第一个数据结点
       s->next = head->next;
       //头结点指向新结点
       head->next = s;
   }
   return head;
}

//12.尾插法建立单链表:维护一个尾指针tail，使其始终指向链表的最后一个结点
//head->[dummy]->10->20->30->tail->nullptr
ListNode* List_tailInsert(int n)
{
    ListNode* head = InitList(); 
    ListNode* tail = head;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        ListNode* s = new ListNode(x);
        //将新结点接到尾部
        tail->next = s;
        //更新尾指针
        tail = s;
    }
    return head;
}

//Q:已知了结点指针 如何在它前面插入？
//13.指定结点前插:已知结点p，在其前面插入元素e 
//技巧：后插新结点+复制原结点数据
//时间复杂度为O(1)
//例如 head->[10]->[20](p)->[30]->nullptr 
//要变成head->[10]->[99]->[20]->[30]->nullptr

//1. head->[10]->[20](p)->[20](s)->[30]->nullptr
//2.head->[10]->[99](p)->[20](s)->[30]->nullptr
//只是实现数据序列上的前插效果 原来的p人干事同一个物理节点 只是数据发生了改变
bool InsertPriorNode(ListNode* p,int e)
{
    //目标结点不存在无法插入
    if(p == nullptr)  return false;
    //s保存p原来的数据 并指向p原来的后继节点
    ListNode* s = new ListNode(p->val,p->next);
    //将p的数据修改为待插入的元素e
    p->val = e;
    //让p指向s 完成链表的连接
    p->next = s;
    return true;
}



//14.指定结点后插 O(1)
bool InsertNextNode(ListNode* p,int e)
{
    if(p==nullptr)  return false;
    ListNode* s = new ListNode(e,p->next);
    p->next = s;
    return true;
}


//15.删除指定非尾节点 O(1)
//已知结点p 删除其代表的数据元素本身(而非其后续结点)
//技巧:既然无法直接删除p 我们偷梁换柱
//让p保存后续节点的数据 然后删除后续结点
//时间复杂度O(1)
bool DeleteNode(ListNode* p)
{
    //p不存在 或者p是尾节点(这样p没有下一个结点，没法偷梁换柱用这个技巧) 都违法
    if(p==nullptr||p->next == nullptr)
    {
        return false;
    }
    ListNode*q = p->next;
    //将q的数据复制到p
    p->val = q->val;
    //让p跳过q,直接连到q的后继去
    p->next = q->next;
    //删除q
    delete q;
    return true;
}
//注:13 和 15 操作的本质相同 都是通过复制数据 
//绕开单链表无法直接访问前驱结点的问题
