#include<bits/stdc++.h>
using namespace std;


// ==========================================
// 链队列（带头结点）
// 本质：仅在表头删除、表尾插入的单链表
// 核心思想：头出尾插
//
// front：始终指向头结点
// rear：始终指向尾结点
//
// 空队列：front == rear
// ==========================================

//1.定义链队列结点
struct QNode
{
   int data;
   QNode* next;
   QNode(int x = 0) : data(x),next(nullptr) {}
};

//2.定义链队列
struct LinkQueue
{
    QNode* front;
    QNode* rear;
    LinkQueue(): front(nullptr),rear(nullptr) {}
};

//3.初始化
// 时间复杂度：O(1)
// 空间复杂度：O(1)
void InitQueue(LinkQueue& Q)
{
    //创建头结点
    Q.front = new QNode();
    //空队列时:队头和队尾指针均指向头结点
    Q.rear = Q.front;
}

//4.判空
// 时间复杂度：O(1)
// 空间复杂度：O(1)
bool QueueEmpty(LinkQueue& Q)
{
    return Q.front == Q.rear;
}

//5.入队:尾插法
// 时间复杂度：O(1)
// 空间复杂度：O(1)
bool EnQueue(LinkQueue& Q,int x)
{
    QNode*s = new QNode(x); // 【Bug修复】：此处传入参数 x，避免节点数据始终为 0
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

//6.出队:删除首元结点
// 时间复杂度：O(1)
// 空间复杂度：O(1)
bool DeQueue(LinkQueue& Q,int& x)
{
    if(QueueEmpty(Q))  return false;
    //p指向首元结点
    QNode* p = Q.front->next;
    //保存出队元素
    x = p->data;
    Q.front->next = p->next;

    //若删除的是最后一个数据结点
    //则必须将rear重新指向头结点
    if(Q.rear == p)
    {
        Q.rear = Q.front;
    }
    delete p;
    return true;
}

//7.获取队头元素(不出队)
// 时间复杂度：O(1)
// 空间复杂度：O(1)
bool GetHead( LinkQueue &Q,int &x)
{
    if(QueueEmpty(Q))  return false;
    x = Q.front->next->data;
    return true;
}

//8.求队列长度
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int QueueLength(const LinkQueue &Q)
{
    int len = 0;
    //从首元结点开始遍历
    QNode* p = Q.front->next;
    while(p!=nullptr)
    {
        len++;
        p = p->next;
    }
    return len;
}

//9.清空队列(保留头结点)
// 时间复杂度：O(n)
// 空间复杂度：O(1)
void ClearQueue(LinkQueue &Q)
{
    QNode* p = Q.front->next;
    while(p!=nullptr)
    {
        QNode* temp = p;
        p = p->next ;
        delete temp;
    }
    //头结点的next置空
    Q.front->next = nullptr; // 【Bug修复】：双等号 == 改为赋值号 =，防止指向野指针
    //队尾指针重新指向头结点
    Q.rear = Q.front;
}

//10.销毁队列(包括头结点)
// 时间复杂度：O(n)
// 空间复杂度：O(1)
void DestroyQueue(LinkQueue &Q)
{
   while(Q.front!=nullptr)
   {
    QNode* temp = Q.front;
    Q.front = Q.front->next;
    delete temp;
   }
   Q.rear = nullptr;  //避免rear变为悬空指针
}
