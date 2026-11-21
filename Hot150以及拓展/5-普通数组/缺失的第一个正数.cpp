/**
 * 41. 缺失的第一个正数
 * 难度: 困难
 * 
 * 题目描述:
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 示例 1：
 * 输入：nums = [1,2,0]
 * 输出：3
 * 解释：范围 [1,2] 中的数字都在数组中。
 * 
 * 示例 2：
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 解释：1 在数组中，但 2 没有。
 * 
 * 示例 3：
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 解释：最小的正数 1 没有出现。
 * 
 * 提示：
 * - 1 <= nums.length <= 10^5
 * - -2^31 <= nums[i] <= 2^31 - 1
 */
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums)
{
    int n = nums.size();
    //将每个有效正整数放到对应下标
    for(int i = 0;i<n;i++)
    {
        //只要当前数字满足以下三个条件 就继续交换
        //1.数字至少为1 排除负数和0
        //2.数字不超过n 保证目标下标合法
        //3.目标位置上还没有相同的数字 当前数字想去第(nums[i]-1)的位置 这个位置的数字不能和当前位置值相同
        while(nums[i]>=1 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
        {
            int target = nums[i] - 1 ;//如果当前数字是x 它应该放在下标x-1的位置
            swap(nums[i],nums[target]);
        }
       
    }
     //找到第一个位置不匹配的元素
        for(int i = 0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
    //所有1到n都存在 则返回n+1
    return n+1;

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
        int ans = solve(nums);
        cout<<ans<<'\n';
    }
    return 0;
}