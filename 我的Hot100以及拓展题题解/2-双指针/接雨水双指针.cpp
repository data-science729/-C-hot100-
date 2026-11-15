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

 //双指针法:时间复杂度O(n)  空间复杂度O(1)
 int solve(vector<int>& height)
 {
    int n = height.size();
    int l = 0;
    int r = n - 1;
    int pre_max = 0;
    int suf_max = 0;
    int ans = 0; 
    while(l < r)
    {
      //动态更新两端的最大值
      pre_max = max(pre_max,height[l]);
      suf_max = max(suf_max,height[r]);
      //谁是短板 就结算谁并向内移动
      if(pre_max<suf_max)
      {
        ans+=pre_max;
        l++;
      }
      else
      {
        ans+=suf_max;
        r--;
      }
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
     for(int i = 0;i<n;i++)
     {
        cin>>height[i];
     }
     int res = solve(height);
     cout<<res<<endl;
    }
    return 0;
 }