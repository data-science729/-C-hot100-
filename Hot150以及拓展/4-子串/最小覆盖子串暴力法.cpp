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

//辅助函数:检查当前子串的频次表window是否完整覆盖了目标need

bool check(const int window[],const int need[])
{
    //遍历所有可能的ASCII字符(主要是大小写字母)
    for(int i = 0 ;i<128;++i)
    {
        //只要有任何一个字符的数量 少于need的要求 就说明还没有覆盖全
        if(window[i]<need[i])
        {
            return false;
        }
    }
    return true;
}

string solve(const string& s ,const string& t)
{
    int m = s.size();
    int n = t.size();
    //边界条件检查:m<n 神仙也凑不齐
    if(m<n)  return "";
    //1.统计目标字符串t中每个字符需要的数量
    int need[128]={0};
    for(char c: t)
    {
        need[c]++;//隐式数据转换
    }
    int start = 0 ;
    int min_len = INT_MAX;
    //2.外层循环遍历子串的起始位置i
    for(int i = 0 ;i<m;i++)
    {
       //当前以i为起点的子串字符频次统计表
       int window[128]={0};
       //3.内层循环:枚举子串的结束位置j
       for(int j = i;j<m;++j)
       {
        window[s[j]]++;   //将新纳入的字符 计入频次
       
       //优化:当前子串长度至少要达到t的长度 才有可能覆盖
       if(j-i+1<n)
       {
        continue;
       }
       //4.检查当前子串s[i...j]是否覆盖了t
       if(check(window,need))
       {
        if(j-i+1<min_len)
        {
            min_len = j-i+1;
            start = i;
        }
        //核心剪枝:对于固定的起点i 当前找到的一定是以i开头最短的合法子串
        //j再往后挪只会让子串更长 没必要继续找了 直接break跳出内层循环
        break;
       }
    }
}
    //如果min_len还是INT_MAX说明没被更新 返回空字符串 否则返回子串start-(start+min_len)部分
    return min_len ==INT_MAX?"":s.substr(start,min_len);
}

int main() {
    // 快速 I/O 优化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    // 多组测试用例循环读取：每次读取两个由字母组成的字符串 s 和 t
    while (cin >> s >> t) {
        cout << solve(s, t) << "\n";
    }

    return 0;
}

