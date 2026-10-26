#include<bits/stdc++.h>
using namespace std;

struct DNode
{
    int val;
    DNode* prior;
    DNode* next;
    DNode():val(0),prior(nullptr),next(nullptr) {}
    DNode(int x):val(x),prior(nullptr),next(nullptr) {}
};

//1.初始化
DNode* InitCDList()
{
    DNode* head = new DNode();
    head->next = head;
    head->prior = head;
    return head;
}

//2.判空
bool EmptyCDList(DNode* head)
{
    //也可以写 head->prior == head, 一样
    return head->next == head;
}

//3(1).循环双链表指定结点后插
//与普通双链表核心区别:不需要判断p->next!=nullptr,能自动处理表尾插入
//插入前:q ⇄ p ⇄ r  
//在p后插入s:q ⇄ p ⇄ s ⇄ r
bool InsertNextDNode(DNode* p,int x)
{
    if(p == nullptr)  return false;
    DNode* s = new DNode(x);
    //引入辅助指针 四句话顺序随便颠倒
    DNode* r = p->next;
    //四句话连四条链
    s->next = r; //[1]
    s->prior = p; //[2]
    r->prior = s; //[3]
    p->next = s; //若没有辅助指针:这句话要放在[1][3]后
    return true;
}

//3(2).循环双链表指定结点前插
//插入前:q ⇄ p ⇄ r  
//在p前插入s:q<-->s<-->p<-->r
bool InsertPriorCDNode(DNode* p,int x)
{
    if(p == nullptr)  return false;
    //直接优雅复用后插函数:前插转换为"前驱结点的后插"
    return InsertNextDNode(p->prior,x);
}


//4(1).循环双链表删除指定结点p
//比普通双链表进步:p->prior->next = p->next后不用特判p->next!=nullptr
//从而可以统一处理普通结点 首元结点和尾结点
//q ⇄ p ⇄ r 变 q ⇄ r
bool DeleteCDNode(DNode* p ,DNode* head)
{
   //不能删除头结点
   if(p == nullptr || p == head)  return false;
   //无顺序要求
   p->prior->next = p->next;
   p->next->prior = p->prior;
   delete p;
   return true;
}

//4(2).循环双链表删除指定结点p的直接后继
//p<-->q<-->r 变 p<-->r
bool DeleteNextCDNode(DNode* p,DNode* head)
{
    if(p==nullptr ||p->next == head)  return false;
    DNode* q = p->next;
    p->next =q->next;
    q->next->prior = p;
    delete q;
    return true;
    //或者优雅复用 return DeleteCDNode(p->next,head)
}


//4(3).循环双链表删除指定结点P的直接前驱
//之前要求p!=nullptr||p->prior!=nullptr||p->prior->prior!=nullptr
//r<-->q<-->p 变 r<-->p
bool DeletePriorCDNode(DNode* p,DNode* head)
{
    if(p == nullptr || p->prior == head)  return false;
    DNode* q = p->prior;
    p->prior = q->prior;
    q->prior->next = p;
    delete q;
    return true;
    //或者优雅复用 return DeletCDNode(p->prior,head)
}

