/**
 * 题目描述：
 * 给定两个正整数 a, b，求 a - b 的值。
 * 
 * 输入格式：
 * 输入共两行，每行一个正整数，分别为 a, b。
 * 
 * 输出格式：
 * 输出一行一个整数，表示 a - b 的值。
 * 如果 a - b < 0，请输出负号。
 * 
 * 输入样例 1：
 * 2
 * 1
 * 输出样例 1：
 * 1
 * 
 * 数据范围与提示：
 * - 对于 20% 的数据：a, b 在 long long 类型的存储范围内；
 * - 对于 100% 的数据：0 < a, b <= 10^10086。
 */
#include<bits/stdc++.h>
using namespace std;

//单独设计一个比较函数 A>=B 返回True 否则false
bool cmp(vector<int>& A,vector<int>& B)
{
    //1.第一步:比较数组长度 数组长的大
    if(A.size() != B.size())
    {
      return A.size()> B.size();
    }
    //2.第二步:长度相同时 从最高位(数组末位)向最低位比较
    //因为决定大小的是从高位开始第一个不相同的数位
    for(int i = A.size()-1;i>=0;i--)
    {
        if(A[i] != B[i])
        {
            return A[i] >B[i];
        }
    }
    //3.完全相等 是等于号状态 为true
    return true;
}
vector<int> solve(vector<int>& A,vector<int>& B)
{
    vector<int> C;
    int maxlength = max(A.size(),B.size());
    int borrow = 0;
    //从低位向高位逐位相减
    for(int i = 0 ;i<maxlength;i++)
    {
        //1.当前位相减
        int t = A[i] - borrow;
        if(i<B.size())  t -= B[i];
        //2.处理错位
        if(t<0)
        {
            t += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        //3.保存当前位
        C.push_back(t);
    }
    //4.当所有数位都计算完成后 再去除最高位的0
    while(C.size()>1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    while(cin>>a>>b)
    {
        vector<int> A,B;
        for(int i =a.size() - 1;i>=0;i--)
        {
            A.push_back(a[i] - '0');
        }
        for(int i = b.size()-1;i>=0;i--)
        {
            B.push_back(b[i] - '0');
        }
        //判断是否需要输出符号
        bool negative = !cmp(A,B);
        //保证A>=B
        if(negative)
        {
          swap(A,B);
        }
        //执行高精度减法
        vector<int> C = solve(A,B);
        if(negative)
        {
            cout<<"-";
        }
        //逆序输出结果
        for(int i = C.size() -1;i>=0;i--)
        {
            cout<<C[i];
        }
        //每组测试用例换行更新
        cout<<"\n";
    }
    return 0;
}