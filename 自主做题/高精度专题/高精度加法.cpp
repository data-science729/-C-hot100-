/**
 * 题目背景：
 * 本题是高精度加法的模板题。
 * 
 * 题目描述：
 * 给定两个非负整数 a, b，求它们的和。不用考虑负数。
 * 
 * 输入格式：
 * 输入共两行，每行一个非负整数，分别为 a, b。
 * 
 * 输出格式：
 * 输出一行一个非负整数，表示 a + b 的值。
 * 
 * 输入样例 1：
 * 1
 * 1
 * 输出样例 1：
 * 2
 * 
 * 输入样例 2：
 * 1001
 * 9099
 * 输出样例 2：
 * 10100
 * 
 * 数据范围与提示：
 * - 对于 20% 的测试数据：a, b <= 10^9
 * - 对于 40% 的测试数据：a, b <= 10^18
 * - 对于 100% 的测试数据：0 <= a, b <= 10^500  -->这个数量级明显需要高精度加法
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& A,vector<int>& B)
{
    vector<int> C;
    int carry = 0;   //进位
    int maxlength = max(A.size(),B.size());
    for(int i = 0 ; i < maxlength;i++)
    {
        int t = carry ; 
       //如果A当前位存在就加上
       if(i < A.size())  t += A[i];
       //如果B当前位存在就加上
       if(i < B.size())  t += B[i];
       //当前位保留个位
       C.push_back(t % 10);
       //计算下一位进位
       carry = t /10 ;
    }
    //如果最高位仍然有进位 需要额外补上
    if(carry)  C.push_back(carry);
    return C;
}

//也很关键 数字变字符
int main()
{
   string a,b;
   //EOF多组输入
   while(cin>>a>>b)
   {
    vector<int> A,B;
    //字符串逆序存入数组[size-1--->0]
    for(int i = a.size() - 1;i>=0;i--)
    {
      A.push_back(a[i] - '0');
    }

    for(int i = b.size() - 1;i>=0;i--)
    {
        B.push_back(b[i] - '0');
    }

    //高精度加法
    vector<int> C = solve(A,B);
    
    //逆序输出
    for(int i = C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
}
   return 0;
}
