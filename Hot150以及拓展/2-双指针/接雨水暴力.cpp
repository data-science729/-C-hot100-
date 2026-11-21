/* ==========================================================
 * 题目名称：接雨水 (Trapping Rain Water)
 * 题目来源：LeetCode 42
 * 
 * 【题目描述】
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
 * 计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 【示例 1】
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：可以接 6 个单位的雨水（蓝色部分表示雨水）。
 * 
 * 【示例 2】
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * ========================================================== */

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& height)
{
    int n = height.size();
    if(n<3)  return 0;  //少于3根柱子存不住水
    int ans = 0;
    //两端0和n-1绝不存水，只需要遍历中间的柱子
    for(int i = 1;i<n-1;i++)
    {
      //找左边柱子的最大值
      int left_max = 0;
      for(int j=0;j<=i;j++)
      {
        left_max = max(left_max,height[j]);
      }
      int right_max = 0;
      for(int k=i;k<n;k++)
      {
        right_max = max(right_max,height[k]);
      }
      //短板决定水面高度，减去自身柱子高度得到本列积水单位数,累加
      ans+= min(left_max,right_max)-height[i];
    }
    return ans;
      
    
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
     vector<int> height(n);
     for(int i=0;i<n;i++)
     {
        cin>>height[i];
     }
     int res = solve(height);
     cout<<res<<endl;
    }
    return 0;
}