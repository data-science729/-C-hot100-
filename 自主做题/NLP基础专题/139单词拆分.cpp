/*
 * 139. 单词拆分 (中等)
 * 链接/来源: LeetCode
 * 
 * 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
 * 如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
 * 
 * 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 
 * 示例 1：
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
 * 
 * 示例 2：
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
 *      注意，你可以重复使用字典中的单词。
 * 
 * 示例 3：
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 提示：
 * - 1 <= s.length <= 300
 * - 1 <= wordDict.length <= 1000
 * - 1 <= wordDict[i].length <= 20
 * - s 和 wordDict[i] 仅由小写英文字母组成
 * - wordDict 中的所有字符串 互不相同
 */

 #include<bits/stdc++.h>
 using namespace std;

bool solve(const string& s, const vector<string>& wordDict)
{
    // 1. 字典存入哈希集合
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    // 2. 直接用 n 表示主串 s 的长度（不需要定义 wordDict.size()）
    int n = s.length(); 
    vector<bool> dp(n + 1, false);
    dp[0] = true; 
    
    // 3. 全程只跟 n（即 s 的长度）打交道
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (!dp[j]) continue; 
            
            string suffix = s.substr(j, i - j); 
            if (wordSet.count(suffix))
            {
                dp[i] = true; 
                break; 
            }
        }
    }

    // 4. 返回主串整体是否能被拼出
    return dp[n]; 
}
 //针对一个主字符串+一个字符串列表的输入的标准输入处理方式
 //第一行 输入主字符串s
 //第二行 输入一个整数 表示字典中有多少个单词
 //第三行 连续输入这n个单词
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n;
    while(cin>>s>>n)
    {
        vector<string> wordDict(n);
        for(int i = 0 ;i<n;i++)
        {
            cin>>wordDict[i]; //依次读入每个字典单词
        }
        bool res = solve(s,wordDict);

        //小技巧:boolalpha 可以让 bool 值输出为"true/false" 而不是1/0
        cout<<boolalpha<<res<<'\n';
    }
    return 0;
}

  
   
   

 



    
  



