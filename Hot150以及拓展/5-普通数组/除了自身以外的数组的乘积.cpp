/**
 * 238. 除了自身以外数组的乘积
 * 难度: 中等
 * 
 * 题目描述:
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积。
 * 题目数据保证数组 nums 之中任意元素的全部前缀元素和后缀的乘积都在 32 位整数范围内。
 * 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 示例 1:
 * 输入: nums = [1,2,3,4]
 * 输出: [24,12,8,6]
 * 
 * 示例 2:
 * 输入: nums = [-1,1,0,-3,3]
 * 输出: [0,0,9,0,0]
 * 
 * 提示:
 * - 2 <= nums.length <= 10^5
 * - -30 <= nums[i] <= 30
 * - 输入保证数组 answer[i] 在 32 位整数范围内
 * 
 * 进阶:
 * 你可以在 O(1) 的额外空间复杂度内完成这个题目吗？
 * (出于对空间复杂度分析的目的，输出数组不被视为额外空间。)
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& nums)
{
     int n = nums.size();
     vector<int> ans(n);
     ans[0] = 1;
     //第一遍遍历(从左往右):计算每个元素左侧所有元素的乘积
     for(int i =1;i<n;i++)
     {
        ans[i] = ans[i-1]*nums[i-1];
     }
     //第二遍遍历(从右往左):用变量R动态维护每个位置右侧所有元素的乘积
     //最右侧元素右边没有元素 初始R=1
     int R = 1;
     for(int i = n-1;i>=0;i--)
     {
        //此时ans[i]存储的是左侧积，直接乘以当前的右侧积R
        ans[i] = ans[i]*R;
        //把当前元素nums[i]乘入R 供左边下一个元素使用
        R*=nums[i];
     }
     return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i = 0;i<n;i++)
        {
            cin>>nums[i];
        }
        vector<int> ans = solve(nums);
        for(int i = 0;i<n;i++)
        {
            cout<<ans[i]<<(i==n-1?'\n':' ');
        }
    }
}

