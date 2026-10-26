#include<bits/stdc++.h>
using namespace std;

const int MaxSize = 100;

//静态链表本质:使用数组存储结点，通过数组下标建立结点之间逻辑关系
//约定nodes[0]是头结点 next=-1代表链表结束
//空闲结点暂时不参与链表
struct SNode
{
    int val;
    int next; //游标:下一个结点的数组下标
    SNode():val(0),next(-1)  {}
    SNode(int v,int n=-1):val(v),next(n) {}
};

SNode nodes[MaxSize];
bool used[MaxSize]; //标记数组位置是否被占用

//1.初始化静态链表
void InitSList()
{
    //0号位置作为头结点
    nodes[0].next = -1;
    used[0] = true;
    for(int i =1;i<MaxSize;i++)
    {
        used[i] = false;
        nodes[i].next = -1;
    }
}

//2.判空
bool EmptySList()
{
    return nodes[0].next == -1;
}

//遍历静态链表
void PrintSList()
{
    int p = nodes[0].next;

    while(p != -1)
    {
        cout << nodes[p].val << " ";
        p = nodes[p].next;
    }

    cout << '\n';
}