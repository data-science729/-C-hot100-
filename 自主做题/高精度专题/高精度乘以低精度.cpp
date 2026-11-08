/*
 * ============================================================
 *  题目：高精度乘低精度
 * ============================================================
 *
 *  【题目描述】
 *    给你一个正整数 a（位数很多，需要高精度存储）和一个正整数 b，
 *    求 a × b。
 *
 *  【输入格式】
 *    第一行：一个正整数，表示 a。
 *    第二行：一个正整数，表示 b。
 *
 *  【输出格式】
 *    输出一行一个整数，表示答案。
 *
 *  【输入输出样例】
 *    ┌───────────────┬─────────────────────┐
 *    │  输入 #1      │  输出 #1            │
 *    ├───────────────┼─────────────────────┤
 *    │  83517934     │  27379735249159740  │
 *    │  327830610    │                     │
 *    └───────────────┴─────────────────────┘
 *
 *  【数据范围】
 *    1 ≤ a ≤ 10^1000000     （a 用字符串或数组按位存储）
 *    1 ≤ b ≤ 10^9           （b 可直接用 long long 存储）
 * ============================================================
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(const vector<int>& A,long long b)
{
     vector<int> C;
     long long carry = 0;
     long long t;
     for(int i = 0;i<A.size();i++)
     {
        int d = A[i];
        t = d*b + carry;
        C.push_back(t%10);
        carry = t/10;
     }
     while(carry)
     {
        C.push_back(carry%10);
        carry/=10;
     }
     while(C.size()>1 && C.back() == 0)
     {
        C.pop_back();
     }
     return C;
}

int main()
{
   string a;
   long long b;
   while(cin>>a>>b)
   {
    vector<int> A;
    for(int i = a.size() - 1;i>=0;i--)
    {
        A.push_back(a[i]-'0');
    }
    vector<int> C = solve(A,b);
    for(int i = C.size() - 1;i>=0;i--)
    {
        cout<<C[i];
    }
    cout<<"\n";
   }
   return 0;
}