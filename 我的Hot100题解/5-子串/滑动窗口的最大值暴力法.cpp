/*
 * 239. 滑动窗口最大值
 * 困难
 * 
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
 * 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 * 返回 滑动窗口中的最大值 。
 * 
 * 示例 1：
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 
 * 示例 2：
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 提示：
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 */
#include<bits/stdc++.h>
using namespace std;

//暴力法
vector<int> solve(vector<int>& nums,int k)
{
   int n = nums.size();
   vector<int> ans ; 
   //外层循环 枚举每个窗口的起始位置i
   //窗口大小为k 所以起点的位置范围是0--(n-k)
   for(int i = 0; i<=n-k;++i)
   {
    //假设当前窗口的第一个数就是最大值
    int cur_max = nums[i];
    //内层循环:扫描窗口内剩下的元素(i+1到i+k-1)
    for(int j = i+1;j<i+k;++j)
    {
       if(nums[j]>cur_max)
       {
        cur_max = nums[j];
       }
    }
    //把当前窗口找出的最大值存入结果数组
    ans.push_back(cur_max);
   }
   return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    while(cin>>n>>k)
    {
      vector<int> nums(n);
      for(int i = 0;i<n;i++)
      {
        cin>>nums[i];
      }
      vector<int> ans = solve(nums,k);
      for(int i = 0;i<(int)ans.size();++i)
      {
        cout<<ans[i]<<(i == (int)ans.size()-1 ? "":" ");
      }
      cout<<"\n";
    }
    return 0;
}