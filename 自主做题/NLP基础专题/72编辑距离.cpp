/**
 * 给你两个单词 word1 和 word2，请返回将 word1 转换成 word2 所使用的最少操作数。
 *
 * 你可以对一个单词进行如下三种操作：
 * 1. 插入一个字符
 * 2. 删除一个字符
 * 3. 替换一个字符
 *
 * 示例 1：
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose  (删除 'r')
 * rose  -> ros   (删除 'e')
 *
 * 示例 2：
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention  (删除 't')
 * inention  -> enention  (将 'i' 替换为 'e')
 * enention  -> exention  (将 'n' 替换为 'x')
 * exention  -> exection  (将 'n' 替换为 'c')
 * exection  -> execution (插入 'u')
 */

 #include<bits/stdc++.h>
 using namespace std;

 int solve(const string& word1,const string& word2)
 {
   int m = word1.size();
   int n = word2.size();

   //1.状态定义 dp[i][j]表示：word1的前i个字符转换为word2前j个字符所需要的最小操作数
    // 创建大小为 (m + 1) x (n + 1) 的二维 vector，初始全为 0
   vector<vector<int>> dp(m+1,vector<int>(n+1,0));

   //2.初始化 Base case
   //第一列:变为空串 需要删除i次
   for(int i = 0 ;i <=m;i++)
   {
    dp[i][0] = i ; //word1的前i个字符 只用删除 变为word2前0个字符 要i次
   }

   //第一行:从空串变过来 需要插入j次
   for(int j = 0 ;j<=n;j++)
   {
    dp[0][j] = j ; //让word1从0个字符开始 只用插入 变为word2的前j个字符 要j次
   }

   //动态规划填表
   for(int i = 1;i<=m;++i)
   {
    for(int j = 1;j<=n;++j)
    {
        //字符相同 免费继承对角线
        if(word1[i-1] == word2[j-1])
        {
            dp[i][j] = dp[i-1][j-1];
        }
        //字符不同 1+min(替换 删除 插入)
        else
        {
            dp[i][j] = 1 + min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
        }
    }
   }
   return dp[m][n];
}


   
 

 int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string word1;
    string word2;
    while(cin>>word1>>word2)
    {
        int res = solve(word1,word2);
        cout<<res<<endl;
    }
    return 0;
 }