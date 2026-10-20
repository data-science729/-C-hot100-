/*
 * 560. 和为 K 的子数组
 * 难度：中等
 * 
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的子数组的个数。
 * 子数组是数组中元素的连续非空序列。
 * 
 * 示例 1：
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 示例 2：
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 提示：
 * - 1 <= nums.length <= 2 * 10^4
 * - -1000 <= nums[i] <= 1000
 * - -10^7 <= k <= 10^7
 */
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums,int k)
{
    unordered_map<int,int> mp;
    mp[0] = 1; //代表 一个数还没选时 前缀和为0的情况已经出现了一次
    int pre_sum = 0;  //记录当前的前缀和
    int count = 0;   //记录符合条件的子数组的总个数
    int n = nums.size();
    for(int i = 0;i<n;i++)
    {
        int x = nums[i];
        pre_sum+=x;
        //核心查询:查看前面是否出现过前缀和为(pre_sum-k)的位置
        //如果出现过 说明从那个位置之后到当前位置的子数组之和刚好是k
        if(mp.find(pre_sum-k)!=mp.end())
        {
            count+=mp[pre_sum-k];
        }
        //满足这个 前缀和为pre_sum的情况++
        mp[pre_sum]++;
        
    }
    return count;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int k;
    while(cin>>n>>k)
    {
      vector<int> nums(n);
      for(int i = 0;i<n;i++)
      {
        cin>>nums[i];
      }
      cout<<solve(nums,k)<<"\n";
    }
    return 0;
}