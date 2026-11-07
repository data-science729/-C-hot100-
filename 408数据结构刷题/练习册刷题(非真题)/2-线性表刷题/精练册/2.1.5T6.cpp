#include "../../../模板/1-线性表模板/循环单链表模板.cpp"
#include<bits/stdc++.h>
using namespace std;
//要在O(1)内实现线性表 A B 头尾链接 用辅助空间最小的是带尾结点的循环单链表
//将循环单链表B链接到A之后
void LinkList(ListNode*& rearA,ListNode*& rearB)
{
   ListNode* headA = rearA->next;
   ListNode* headB = rearB->next;
   rearA->next = headB->next;
   rearB->next = headA;

}