/*
 * ==============================================================================
 * 53. 最大子数组和
 * 难度：中等
 * 
 * 题目描述：
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组
 * （子数组最少包含一个元素），返回其最大和。
 * 子数组是数组中的一个连续部分。
 * 
 * 示例 1：
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 
 * 示例 2：
 * 输入：nums = [1]
 * 输出：1
 * 
 * 示例 3：
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 * 
 * 提示：
 * - 1 <= nums.length <= 10^5
 * - -10^4 <= nums[i] <= 10^4
 * 
 * 进阶：
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * ==============================================================================
 */
#include<bits/stdc++.h>
using namespace std;

void solve(int n)
{
    
    vector<int> nums(n);
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }
    //current表示以当前位置结尾的最大子数组和
    //ans表示遍历过程中出现过的最大子数组和
    int current = nums[0] ; // 初始状态 第一个元素是唯一选择
    int ans = nums[0]; 
    //从第二个元素开始进行状态转移
    for(int i = 1;i<n;i++)
    {
        current = max(nums[i],current+nums[i]);
        ans = max(ans,current);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
    {
        solve(n);
    }
    return 0;
}