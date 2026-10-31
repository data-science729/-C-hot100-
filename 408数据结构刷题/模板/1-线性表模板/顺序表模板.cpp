#include<bits/stdc++.h>
using namespace std;

const int MaxSize = 1000 ;

struct SqList
{
  int data[MaxSize];
  int length = 0;
  SqList()  {length = 0;}
};

//1.初始化顺序表 O(1)      
void InitList(SqList& L)
{
    L.length = 0;
}

//2.求表长 O(1)
int Length(const SqList & L)
{
    return L.length;
}

//3.判断是否为空 O(1)
bool isEmpty(const SqList& L)
{
    return L.length == 0;
}

//4.按位查找元素 O(1)
bool GetElem(const SqList& L,int i,int & e)
{
    if(i<1 || i>L.length)
    {
        return false;
    }
    e = L.data[i-1];
    return true;
}

//5.按值查找 返回第一次出现的位置 O(n)
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

//6.插入元素 O(n)
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
    //从逻辑i(包括i)(下标i-1)到n 从后向前后挪(n->i) 元素
    for(int j = L.length;j>=i;j--)
    {
        L.data[j] = L.data[j-1]; //原来逻辑j(下标j-1) 变到逻辑j+1(下标j)
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//7.按位删除元素 O(n)
bool ListDelete(SqList& L,int i,int& e)
{
    if(i<1||i>L.length)
    {
        return false;
    }
    e = L.data[i-1];
    //从逻辑i+1(下标i)到n 从前向后前挪(i->n) 元素
    for(int j =i;j<L.length;j++)
    {
        L.data[j-1] = L.data[j]; //原来逻辑j+1(下标j) 变到逻辑j(下标j-1)
    }
    L.length--;
    return true;
}



//8.输出线性表 O(n)
void printList(const SqList& L)
{
    for(int i = 0;i<L.length;i++)
    {
        if(i>0)  cout<<' ';
        cout<<L.data[i];
    }
    cout<<'\n';
}



