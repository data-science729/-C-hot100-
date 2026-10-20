/*
 * 76. 最小覆盖子串
 * 难度：困难
 * 
 * 给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，
 * 使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。
 * 测试用例保证答案唯一。
 * 
 * 示例 1：
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 * 
 * 示例 2：
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 * 
 * 示例 3：
 * 输入：s = "a", t = "aa"
 * 输出：""
 * 解释：t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 提示：
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 * 
 * 进阶：你能设计一个在 O(m + n) 时间内解决此问题的算法吗？
 */
#include<bits/stdc++.h>
using namespace std;

void solve(const string& s, const string& t) {
    int need[128] = {0}; //目标字符串t中字符c需要出现的次数
    int window[128] = {0};  //当前滑动窗口中字符c实际出现的次数

    // 1. 统计 t 中各字符的需求次数
    for (char c : t) {
        need[c]++;
    }
    //2.统计需要满足的字符种类数
    int required = 0;  //t中需要满足的字符种类数(而非字符总数)
    for(int i = 0;i<128;i++)
    {
        if(need[i]>0)
        {
            required++;
        }
    }
    //滑动窗口[left,right),right指向下一个准备加入窗口的字符，left指向当前窗口最左边的字符
    int left = 0,right = 0;
    int valid = 0; //当前窗口中，已经满足需求次数的字符种类数
    int start = 0;
    int minLen = INT_MAX;
    //3.滑动窗口 右指针不断向右扩张
    while(right<(int)s.size())
    {
        char c = s[right++] ; //将右端的字符加入窗口
        //只有t中需要的字符 才会影响窗口是否合法
        if(need[c]>0)
        {
            window[c]++;  
            //只有当字符c的数量刚好达到要求时 valid才增加
            if(window[c] == need[c])
            {
                valid++;
            }
        }
        //窗口合法时 此时不断尝试缩小左边界 寻找更短的合法子串
        while(valid == required)
        {
            //先记录当前的合法窗口
            if(right-left<minLen)
            {
                minLen = right - left;
                start = left;
            }
            //准备移除窗口最左端的字符d
            char d = s[left++];
            if(need[d]>0)
            {
                //如果删除前"恰好满足要求" 而非window[d]严格大于need[d] 那么删除后d是缺少的
                if(window[d] == need[d])
                {
                    valid--; //这时字符种类d开始不满足覆盖 valid必须减少1
                }
                window[d]--; //更新当前窗口中字符d的实际数量
            }
        }
    }
    //输出最短长度子串
    if(minLen== INT_MAX)
    {
        cout<<""<<'\n';
    }
    else
    {
        cout<<s.substr(start,minLen)<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t;
    while(cin>>s>>t)
    {
        solve(s,t);
    }
    return 0;
}