/*
 * ============================================================
 *  题目：高精度乘法
 * ============================================================
 *
 *  【题目描述】
 *    给你两个正整数 a、b，求 a × b。
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
 *    1 ≤ a, b ≤ 10^1000000
 * ============================================================
 */
#include<bits/stdc++.h>
using namespace std;

//语法复习:在类型后:&是别名 A是传进来的那个vector的别名
//在表达式后: &是取地址
//const 只能读不能改:通过A这个名字 不能修改原数组
vector<int> solve(const vector<int>& A, const vector<int>& B)
{
    int length = A.size() + B.size();
    vector<int> C(length, 0);

    // 1. 累加：a_i * b_j 落在第 i+j 位
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < B.size(); j++)
            C[i + j] += A[i] * B[j];

    // 2. 从低位到高位统一进位
    for (size_t k = 0; k + 1 < C.size(); k++)
    {
        C[k + 1] += C[k] / 10;
        C[k] %= 10;
    }

    // 3. 去掉高位多余的 0
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    while(cin>>a>>b)
    {
        vector<int> A;
        vector<int> B;
        for(int i = a.size() -1;i>=0;i--)
        {
           A.push_back(a[i] - '0');
        }
        for(int i =b.size() - 1;i>=0;i--)
        {
            B.push_back(b[i] - '0');
        }
        vector<int> C = solve(A,B);
        for(int i = C.size() - 1;i>=0;i--)
        {
            cout<<C[i];
        }
        cout<<"\n";
    }
    return 0;
}