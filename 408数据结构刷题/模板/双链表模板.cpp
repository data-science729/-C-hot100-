#include<bits/stdc++.h>
using namespace std;


//双链表结点定义
struct DNode
{
    int val;
    DNode* prior;
    DNode* next;
    DNode():val(0),prior(nullptr),next(nullptr) {}
    DNode(int x):val(x),prior(nullptr),next(nullptr) {}
      // 同时指定前驱和后继
    DNode(int x, DNode* p, DNode* n)
        : val(x), prior(p), next(n) {}
};

//1.双链表初始化
DNode* InitDList()
{
    return new DNode();
}

//2.判空
bool Empty(DNode* head)
{
    return head->next ==nullptr;
}

// 3. 指定结点后插 O(1)
//已知结点p 在其后面插入元素e
//p<-->q 变  p<-->s<-->q
bool InsertNextDNode(DNode* p, int e)
{
   if(p==nullptr)
   {
    return false;
   }
   DNode* s = new DNode(e);
   //1.让新结点指向原后继
   s->next = p->next;
   //2.让新结点的前驱指向p
   s->prior = p;
   //3.修改原后继结点的前驱
   if(p->next!=nullptr)
   {
    p->next->prior = s;
   }
   //4.让p的后继指向新节点
   p->next = s;
   return true;
}

// 4. 指定结点前插 O(1) 等价于找到前驱 在前驱后插
//已知结点p 在其前面插入元素e
bool InsertPriorDNode(DNode* p, int e)
{
     //p必须存在前驱节点
     if(p==nullptr||p->prior == nullptr)
     {
        return false;
     }
     //找到p的前驱结点
     DNode* q = p->prior;
     //转换为在q后面插入新结点
     return InsertNextDNode(q,e);
}

// 5(1). 删除当前结点 O(1)
//删除当前指定结点p
//q<-->p<-->r  变q<-->r
bool DeleteDNode(DNode* p)
{
  //p必须是有效数据结点 如头结点prior为nullptr就不行
  if(p==nullptr||p->prior==nullptr)
  {
    return false;
  }
  if(p->next!=nullptr)
  {
    p->next->prior = p->prior;
  }
  p->prior->next = p->next;
  delete p;
  return true;
}

//5(2).删除指定结点p的直接后继 O(1)
//p<-->q<-->r 变 p<-->r
bool DeleteNextDNode(DNode* p)
{
    //p必须存在且有直接后继(删后继时 后继可以是尾节点)
    if(p==nullptr||p->next==nullptr)
    {
        return false;
    }
    //q是待删除结点
    DNode* q = p->next;
    //如果q不是尾节点 让q的后继指向p
    if(q->next!=nullptr)
    {
        q->next->prior = p;
    }
    p->next = q->next;
    delete q;
    return true;
}

//5(3).删除指定结点p的直接前驱O(1)
//q<-->r<-->p 变 q<-->p
bool DeletePriorNode(DNode* p)
{
    //p和p的前驱必须存在(且删前驱时不能删除头结点)
    if(p==nullptr||p->prior ==nullptr||p->prior->prior==nullptr)
    {
        return false;
    }
    //r是待删除结点
    DNode* r = p->prior;
    if(r->prior!=nullptr)
    {
       r->prior->next = p;
    }
    p->prior = r->prior;
    delete r;
    return true;
}


// 6. 正向遍历 O(n)
void PrintForward(DNode* head)
{
  DNode* p = head->next;
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

// 7. 反向遍历 O(n) 
//双链表可以沿prior指针反向遍历
//如果只保留头指针head 我们需要先找到尾结点
void PrintBackward(DNode* head)
{
    DNode* p = head;
    //先找到尾结点 O(n)
    while(p->next!=nullptr)
    {
        p = p->next;
    }
    //再沿着prior反向遍历  O(n)
    while(p!=head)
    {
        cout<<p->val;
        if(p->prior!=head)
        {
            cout<<' ';
        }
        p = p->prior;
    }
    cout<<'\n';
}

// 8. 销毁链表 O(n) 包括头结点
void DestroyDList(DNode*& head)
{
   while(head!=nullptr)
   {
      DNode* temp  = head;
      head = head->next;
      delete temp ;
   }
}




