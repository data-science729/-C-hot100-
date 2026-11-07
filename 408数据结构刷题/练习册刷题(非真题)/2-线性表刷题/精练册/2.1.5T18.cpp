#include "../../../模板/1-线性表模板/循环单链表模板.cpp"
#include<bits/stdc++.h>
using namespace std;

/**
 * 题目 18：
 * 设有一个带头结点的循环单链表，其结点值均为正整数。
 * 设计一个算法，反复找出单链表中结点值最小的结点并输出，
 * 然后将该结点从表中删除，重复此过程直到单链表空为止，
 * 最后再删除头结点。
 * 
 * 函数声明参考：
 * void Del_Min(ListNode* head);
 */

//核心:要删除结点 首先要找到它的前驱结点 
//再执行pre->next = p->next  delete p
void Del_Min(ListNode* head)
{
    //如果是空指针 直接返回
    if(head == nullptr)  return;
    while(head->next != head)
    {
        //初始化遍历指针 pre是工作遍历指针p前驱
        ListNode* pre = head;
        ListNode* p = head->next;
        //初始化记录最小值的指针 minpre是记录最小值指针minp前驱
        ListNode* minpre = head;
        ListNode* minp = head->next;

        //遍历整个循环单链表(转一圈到head为止)
        while(p != head)
        {
            if(p->val<minp->val)
            {
                minp = p;  //更新minp
                minpre = pre; //同步更新前驱指针
            }
            //指针同步向后推进
            pre = p;
            p = p->next;
        }
        //一轮扫描完毕 输出本轮最小值+删除它+释放内存
        cout<<minp->val<<" ";
        //先从链表中摘除 再释放内存
        //含义:让结点的前驱直接指向结点后继
        //从而把结点从链表中跳过去
        minpre->next = minp->next;
        delete minp;
    }
     cout<<"\n";
     //最后再删除头结点
     delete head;  
}