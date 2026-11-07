#include "../../../模板/1-线性表模板/循环双链表模板.cpp"
#include<bits/stdc++.h>
using namespace std;

//编写一个函数 实现结点p和其右边的一个结点进行交换prev<-->p<-->q<-->nxt 变prev<-->q<-->p<-->nxt
bool Swap(DNode* p)
{
   //1.先判空 再判断是否只有一个结点(这两个情况不能交换)
   if(p->next == nullptr ||p->next == p)  return false;
   DNode* prev = p->prior;
   DNode* q = p->next;
   DNode* nxt = q->next;
   //2.特判(避免自环:一个结点的指针指向自己):如果环中只有两个结点p<-->q 此时q->next = p 
   if(nxt == p)  return true;  //本来就是互为左右 无需重连指针 直接返回
   prev->next = q;
   q->prior = prev;
   q->next = p;
   p->prior = q;
   p->next = nxt;
   nxt->prior = p;
   return true;
}

//设计一个算法用于判断带头结点的循环双链表是否对称
//法:循环双链表是双指针的绝配 next向后走,prior向前走
//head->next是首结点，head->prior是尾结点
bool isSymmetric(DNode* head)
{
   //空表对称
   if(head == nullptr || head->next == head)
   {
      return true;
   }
   DNode* p = head->next; //第一个有效数据结点
   DNode* q = head->prior; //最后一个有效数据结点、
   //左右两个指针是否还没有到达中间 且没有相互越过
   //奇数个结点:两个指针最终相遇(p==q)
   //偶数个结点:p刚好越过q(q->next=p/p->prior=q)
   //为何可以结束：
   while(p!=q && q->next!=p)
   {
     //对应位置值不相等 不对称
     if(p->val != q->val)  return false;
     p = p->next; //p向右移动
     q = q->prior;  //q向左移动
   }
   return true;
}