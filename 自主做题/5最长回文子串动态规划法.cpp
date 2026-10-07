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
    if(n<=1)  return s;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    int max_len = 1;
    int start = 0 ;
    //区间DP核心套路 第一层循环从小到大枚举区间长度len
    for(int len = 1;len<=n;++len)
    {
        //第二层循环枚举左端点i 右端点j = i+len-1
        for(int i = 0;i+len-1<n;++i)
        {
             int j = i+len-1;
             if(s[i]==s[j])
             {
                if(len<=3)  
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i+1][j-1];
                }
             }
             else
             {
                dp[i][j] = false;
             }
             //如果当前区间是回文 更新全局最大值
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

