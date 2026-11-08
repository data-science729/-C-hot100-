// P1480 A/B Problem（高精度除法Ⅰ）
// 提交 203.56k  通过 66.61k
// 时间限制 1.00s  内存限制 128.00MB
//
// 题目描述
// 输入两个整数 a, b，输出它们的商。
//
// 输入格式
// 两行，第一行是被除数，第二行是除数。
//
// 输出格式
// 一行，商的整数部分。
//
// 输入输出样例
// 输入 #1
// 10
// 2
// 输出 #1
// 5
//
// 说明/提示
// 0 ≤ a ≤ 10^5000，1 ≤ b ≤ 10^9。
//
// 题目编号 P1480，提供者 Timothy，难度 普及−
// 标签：（无）

#include<bits/stdc++.h>
using namespace std;

// 高精度整数除以普通整数
string solve(string& a, long long b)
{
    string C;          // 存储商
    long long r = 0;   // 当前余数

    // 从最高位向最低位遍历
    for(int i = 0; i < a.size(); i++)
    {
        // 1. 当前数位转换为整数
        int d = a[i] - '0';

        // 2. 构造当前被除数
        long long t = r * 10 + d;

        // 3. 计算当前商位
        int q = t / b;

        // 4. 更新余数
        r = t % b;

        // 5. 保存当前商位
        C.push_back('0' + q);
    }

    // 6. 去除商的前导零
    while(C.size() > 1 && C[0] == '0')
    {
        C.erase(C.begin());
    }

    return C;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    long long b;

    // 多组输入，EOF 结束
    while(cin >> a >> b)
    {
        string C = solve(a, b);
        cout << C << '\n';
    }

    return 0;
}
