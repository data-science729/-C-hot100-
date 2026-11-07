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

//辅助函数 双指针检验子串s[left...right]是否为回文串
bool isPalindrome(const string& s,int left,int right)
{
    while(left<right)
    {
        if(s[left]!=s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string solve(const string& s)
{
    int n = s.size();
    if(n<=1) return s;
    int max_len = 1;
    int start = 0;
    //枚举所有子串起点i
    for(int i = 0 ;i<n;++i)
    {
        //枚举所有子串终点j
        for(int j = i;j<n;++j)
        {
         int curr_len = j-i+1;
         //关键剪枝:如果当前子串长度根本没有突破当前记录，直接跳过不检查
         if(curr_len<=max_len)
         {
            continue;
         }
         if(isPalindrome(s,i,j))
         {
            max_len = curr_len;
            start = i;
         }
        }
    }
    return s.substr(start,max_len);
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   string s;
   while(cin>>s)
   {
    cout<<solve(s)<<"\n";
   }
   return 0;
}