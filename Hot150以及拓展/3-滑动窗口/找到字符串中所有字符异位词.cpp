/**
 * 438. 找到字符串中所有字母异位词
 * 
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。
 * 不考虑答案输出的顺序。
 * 
 * 示例 1:
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 示例 2:
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 提示:
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(const string& s,const string& p)
{
    vector<int> ans;
    int n = s.length();
    int m = p.length();
    //本题 滑动窗口大小是固定的m
    if(n<m)  return {}; //边界 如果s比p短 无论如何装不下p的异位词 直接返回空数组
    vector<int> p_cnt(26,0); //均为小写英文字母 故只开26
    for(char c: p)
    {
        p_cnt[c-'a']++; //统计字符串p中的字符频次
    }
    //动态维护窗口内字符的频次
    vector<int> s_cnt(26,0);
    for(int r = 0 ;r<n;r++)
    {
        s_cnt[s[r]-'a']++; //进窗
        //我们需要的是 从第m-1个位置开始 窗口只要维持在大小为m 此后的每一步r>=m-1都需要进行一次比对
        if(r>=m-1)
        {
            s_cnt[s[r-m]-'a']-- ; //出窗:当窗口大小超过m时 移出最左侧字符
        }
        //比对:当窗口大小刚好达到m时 检查两个计数器是否完全一致
        if(r==m)
        {
            if(s_cnt == p_cnt)
            {
                ans.push_back(r-m+1); //则起始下标r-m+1就是当前窗口的最左端
            }
        }
    }
    return ans;
}
   
   
    





int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   string s,p ;
 //连续读入 s 和 p，无论它们是空格隔开还是换行隔开都能完美支持
   while(cin>>s>>p)
   {
    vector<int> res = solve(s,p);
    
    cout<<"[";
    int n = res.size();
    for(int i = 0;i<n;i++)
    {
        cout<<res[i];
        if(i+1<n) cout<<",";
    }
    cout<<"]"<<endl;
   }
   return 0 ; 
}