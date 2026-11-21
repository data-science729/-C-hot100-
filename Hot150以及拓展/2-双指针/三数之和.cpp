/**
 * @file   three_sum.cpp
 * @brief  三数之和 (LeetCode 15)
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足：
 *   1. i != j、i != k 且 j != k
 *   2. nums[i] + nums[j] + nums[k] == 0
 * 请返回所有和为 0 且不重复的三元组。
 *
 * @note   答案中不可以包含重复的三元组。
 *
 * 示例 1：
 *   输入：nums = [-1,0,1,2,-1,-4]
 *   输出：[[-1,-1,2],[-1,0,1]]
 *   解释：
 *     nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0
 *     nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0
 *     nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0
 *     不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 *     注意，输出的顺序和三元组的顺序并不重要。
 *
 * 示例 2：
 *   输入：nums = [0,1,1]
 *   输出：[]
 *   解释：唯一可能的三元组和不为 0 。
 *
 * 示例 3：
 *   输入：nums = [0,0,0]
 *   输出：[[0,0,0]]
 *   解释：唯一可能的三元组和为 0 。
 *
 * 提示：
 *   - 3 <= nums.length <= 3000
 *   - -10^5 <= nums[i] <= 10^5
 */
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(const vector<int>& nums)
{
    int n = nums.size();
    set<vector<int>> unique_triplets;
    
    
    for(int i = 0;i<n;i++)
    {
        for(int j =i+1;j<n;j++)
        {
            for(int k = j+1;k<n;k++)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                   vector<int> triplet ={nums[i],nums[j],nums[k]};
                   sort(triplet.begin(),triplet.end());
                   unique_triplets.insert(triplet);
                }
            }
        }
    }
    //把set转为vector<vector<int>>返回
    return vector<vector<int>>(unique_triplets.begin(),unique_triplets.end());

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
   
    while(cin>>n)
    {
     
     vector<int> nums(n);
     for(int i=0;i<n;i++)
     {
        cin>>nums[i];
     }
     vector<vector<int>> res = solve(nums);
     //打印二维数组结果
     cout<<"[";
     for(size_t i=0;i<res.size();i++)
     {
        cout<<"["<<res[i][0]<<","<<res[i][1]<<","<<res[i][2]<<"]";
        if(i+1<res.size())  cout<<",";
     }
     cout<<"]\n";
     
     
    }
    return 0;
}
