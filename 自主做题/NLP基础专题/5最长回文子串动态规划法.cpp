/*
 * 5. 最长回文子串 (Medium)
 * 
 * 题目描述：
 * 给定一个字符串 s，返回 s 中最长的回文子串。
 * 
 * 示例 1：
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 提示与约束：
 * - 1 <= s.length <= 1000
 * - s 仅由数字和英文字母组成。
 */
#include<bits/stdc++.h>
using namespace std;

string solve(const string& s)
{
    int n = s.size();
    //边界特判:空串或者字符串本身就是最长回文串 直接返回
    if(n<=1)  return s;
    //dp[i][j]含义为子串s[i....j]是否为回文子串 全部初始化为false
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    //记录最长回文子串的起始位置和长度(不每次去s.substr()截取 大幅降低开销)
    int max_len = 1;
    int start = 0 ;
    //区间DP核心套路 第一层循环从小到大枚举区间长度len
    //循环不变量:当外层len计算到k时 所有长度<k的子串结果都已经存入dp表中
    for(int len = 1;len<=n;++len)
    {
        //第二层循环枚举左端点i 右端点j = i+len-1
        for(int i = 0;i+len-1<n;++i)
        {
             int j = i+len-1; //由长度和左端点计算出右端点j
             //情况1:两端字符相等
             if(s[i]==s[j])
             {
                //长度为1 2 3 时无需查内层 直接为true
                //如3:满足if(s[i] ==s[j])的第一次条件 首尾相等 然后中间只夹一个字符必然回文
                if(len<=3)  
                {
                    dp[i][j] = true;
                }
                else
                {
                    //长度大于3 由剥去两端后的内部子串决定
                    dp[i][j] = dp[i+1][j-1];
                }
             }
             //情况2:两端字符不相等 必然不是回文
             else
             {
                dp[i][j] = false;
             }
             //如果当前区间[i...j]是回文串 且长度严格大于之前的最大长度 则更新答案
             if(dp[i][j] && len>max_len)
             {
                max_len = len;
                start = i;
             }
        }
    }
     return s.substr(start,max_len);
}

int main() {
    // 快速 I/O 优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    // ACM 多组测试用例循环读取
    while (cin >> s) {
        cout << solve(s) << "\n";
    }
    return 0;
}

