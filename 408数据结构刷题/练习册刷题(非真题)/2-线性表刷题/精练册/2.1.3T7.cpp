
//这种自定义include 用双引号"",.表示当前目录,..表示上一级目录
//从当前文件 退到两者共同祖先要几层 就写几个../
#include "../../../模板/1-线性表模板/单链表模板.cpp"
#include<bits/stdc++.h>
using namespace std;
//将长度为n的单链表链接在长度为m的单链表后的算法
void LinkList(ListNode* A,ListNode* B)
{
    if(A == nullptr ||B == nullptr)
    {
        return ;
    }
    //1.找到链表A的尾结点  O(m)
    ListNode* p = A;
    while(p->next!=nullptr)
    {
        p = p->next;
    }
    //将A尾结点的next指向B的第一个有效数据结点
    p->next = B->next; 
    //释放B的头结点(已无用 变成一条链)
    delete B;
}