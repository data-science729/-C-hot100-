/*
 * =====================================================================
 * 3. 无重复字符的最长子串 (中等)
 * =====================================================================
 * 题目描述：
 *   给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
 * 
 * 示例 1:
 *   输入: s = "abcabcbb"
 *   输出: 3 
 *   解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *        注意 "bca" 和 "cab" 也是正确答案。
 * 
 * 示例 2:
 *   输入: s = "bbbbb"
 *   输出: 1
 *   解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 示例 3:
 *   输入: s = "pwwkew"
 *   输出: 3
 *   解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *        请注意，你的答案必须是子串的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 提示：
 *   - 0 <= s.length <= 10^5
 *   - s 由英文字母、数字、符号和空格组成
 * =====================================================================
 */

 //技巧:对于字符哈希 我们不推荐用unordered_map<char,int> window
 //我们直接用固定大小的数组(桶排序的思想) ASCII码总共只有128个字符
 //理由:数组访问是CPU寄存器级别的寻址，哈希表是多级指针间接寻址
#include<bits/stdc++.h>
using namespace std;

int solve(const string& s)
{
    int n = s.length();
    if(n<=1)  return n ;

    int max_len = 0;
    //外层循环 枚举子串的左起点 i
    for(int i = 0; i<n;i++)
    {
        //每次固定左端点i时，重置查重数组
        //标准ASCII码有128个字符 足以覆盖大小写字母 数字 符号和 空格
        bool seen[128] = {false};

        for(int j = i ; j<n;j++)
        {
            char c = s[j];
            //遇到重复字符立即斩断 以i开头更长的子串不用再看
            if(seen[c])
            {
                break;
            }
            //没重复 标记为已访问 并更新最大长度
            seen[c] = true;
            max_len = max(max_len,j-i+1);
        }

    }
    return max_len;
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    while(getline(cin,s))
    {
        int res = solve(s);
        cout<<res<<endl;
    }
    return 0;
}