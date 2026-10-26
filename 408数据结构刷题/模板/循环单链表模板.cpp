#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

//1.初始化
ListNode* InitCList()
{
    ListNode* head = new ListNode();
    head->next = head; //这表明:空的CList 头结点的next指向自己
    return head;
}

//2.判空
bool EmptyCList(ListNode* head)
{
    return head->next == head;
}

//3.遍历
void PrintCList(ListNode* head)
{
    ListNode* p = head->next;
    while(p!=head)
    {
        cout<<p->val;
        if(p->next!=head)
        {
            cout<<' ';
        }
        p = p->next;
    }
    cout<<'\n';
}

//4.普通插入 若已知结点指针p后插O(1) 前插后插和单链表没区别 

bool InsertNextCNode(ListNode* p, int x)
{
    if(p == nullptr)
    {
        return false;
    }

    ListNode* s = new ListNode(x);

    s->next = p->next;
    p->next = s;

    return true;
}

//5.在循环单链表的表头表尾插入新结点,O(1)

//在表头插入新元素
//链表为空时需要更新tail
//原链表:head->A->B->.....->tail->head
//插入后:head->s->A->B->....tail->head
//为何用引用传递?：为了防范链表原本是空表
bool InsertHead_CList(ListNode*& tail,int x)
{
    if(tail == nullptr) return false;
    ListNode* head = tail->next; //O(1)定位头结点
    ListNode* s = new ListNode(x);
    //后插
    s->next = head->next;
    head->next = s;
    //如果原表是空表 新插入的结点是尾节点
    //原:head->head
    //插入后:head->s(充当tail)->head
    if(tail == head)
    {
        tail = s; //此时新节点既是第 1 个节点，同时也成了整条链表的【尾节点】！
    }
    return true;
}

//在循环单链表表尾插入新元素O(1)
//每次都需要更新tail
//原链表:head->A->B->tail->head
//插入后:head->A->B->tail->s->head
bool InsertTail_CList(ListNode*& tail,int x)
{
    if(tail == nullptr)  return false;
    ListNode* s = new ListNode(x);
    s->next = tail->next; //新结点指向头结点
    tail->next = s; //原尾节点指向新结点
    tail = s;  //更新尾指针指向新结点
    return true;
}


//6.删除指定结点p的直接后继
// p->q->r 变p->r  r写做p->next
bool DeleteNextCNode(ListNode* p,ListNode* head)
{
    //注意判断条件和单链表不同 是p->next==head 防止误删头结点
    if(p == nullptr || p->next == head)
    {
        return false;
    }
    ListNode* q = p->next;
    p->next = q->next;
    delete q;
    return true;
}

//7:表头删除(删除第一个有效数据结点)O(1)
//原链表:head->A->B->tail->head 第一个有效数据结点是A
//删除后:head->B->tail->head
//但若只剩head->tail 删tail后成为空表则必须令tail=head
bool DeleteHead_CList(ListNode*& tail)
{
    if(tail == nullptr)  return false;
    ListNode* head = tail->next;
    //空表
    if(head->next == head)
    {
        return false;
    }
    ListNode* q = head->next; //q指向待删除的首元结点
    head->next = q->next; //头结点越过q 指向下一个结点
    //如果q就是尾结点
    if(q == tail)
    {
        tail == head; //这样head->next = head 变空表
    }
    delete q;
    return true;
}

//8.表尾删除(删除最后一个数据结点) O(n)
//原链表:head->A—>B(tail所指)->head
//删除后:head->A->head
bool DeleteTail_CList(ListNode*& tail)
{
   //防御性检查:防止外部传入一个未初始化的空指针
   if(tail == nullptr) return false;
   ListNode* head = tail->next; //O(1)获取头结点
   //空表 
   if(tail == head)
   {
     return false;
   }
   //寻找原尾结点tail的直接前驱
   ListNode* p = head;
   while(p->next!=tail)
   {
     p = p->next;
   }
   //跨过尾结点 重新闭合成环
    p->next = head;
    delete tail;
    tail = p; //更新尾指针的指向
    return true;
}