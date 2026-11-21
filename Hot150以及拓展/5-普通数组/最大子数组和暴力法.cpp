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

void solve()
{
    int n ;
    
    vector<int> nums(n);
    //输入数组
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }
    //prefix[i]表示nums[0]到nums[i-1]的元素和
    //注意 prefix[0]=0方便处理从第0个元素开始的情况
    vector<int> prefix(n+1,0);
    //构造前缀和数组
    for(int i = 0;i<n;i++)
    {
        prefix[i+1] = prefix[i] + nums[i] ;
    }
    //初始化答案 因为答案要求至少包含一个元素
    int ans = INT_MIN;
    //枚举左端点i
    for(int i = 0 ;i<n;i++)
    {
        //枚举右端点j 则当前为子数组nums[i...j]
        for(int j = i;j<n;j++)
        {
            int sum = prefix[j+1]-prefix[i];
            //更新最大答案
            ans = max(ans,sum);
        }
        
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
       solve();
    }
    return 0;
}
