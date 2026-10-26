#include<bits/stdc++.h>
using namespace std;

const int MaxSize = 1000 ;

struct SqList
{
  int data[MaxSize];
  int length = 0;
  SqList()  {length = 0;}
};

//初始化顺序表      
void InitList(SqList& L)
{
    L.length = 0;
}

//求表长
int Length(const SqList & L)
{
    return L.length;
}

//判断是否为空
bool isEmpty(const SqList& L)
{
    return L.length == 0;
}

//按位查找
bool GetElem(const SqList& L,int i,int & e)
{
    if(i<1 || i>L.length)
    {
        return false;
    }
    e = L.data[i-1];
    return true;
}

//按值查找 返回第一次出现的位置
int LocateElem(const SqList& L,int e)
{
    for(int i = 0;i<L.length;i++)
    {
        if(L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0; //未找到
}

//插入元素
bool ListInsert(SqList& L,int i,int e)
{
    if(i<1 || i>L.length+1)
    {
        return false;
    }
    if(L.length>=MaxSize)
    {
        return false;
    }
    //从后向前移动元素
    for(int j = L.length;j>=i;j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//删除元素
bool ListDelete(SqList& L,int i,int& e)
{
    if(i<1||i>L.length)
    {
        return false;
    }
    e = L.data[i-1];
    //从前往后移动元素
    for(int j =i;j<L.length;j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//输出线性表
void printList(const SqList& L)
{
    for(int i = 0;i<L.length;i++)
    {
        if(i>0)  cout<<' ';
        cout<<L.data[i];
    }
    cout<<'\n';
}


