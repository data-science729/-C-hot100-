/**
 * 215. 数组中的第K个最大元素
 * 难度：中等
 *
 * 【题目描述】
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 * 【示例 1】
 * 输入: nums = [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 * 【示例 2】
 * 输入: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 * 【提示】
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 */

//记住:求前K大 用容量为K的小顶堆 堆顶就是第K大
#include<bits/stdc++.h>
using namespace std;

//时间复杂度O(NlogK)  空间复杂度O(K)
int solve(const vector<int>& nums,int k)
{

   
    priority_queue<int,vector<int>,greater<int>> min_heap;
    for(int x: nums)
    {
        //新候选人入堆
        min_heap.push(x);
        //一旦堆的大小超过k，把堆内最小的那个淘汰掉(即第K+1大)
        
        if(min_heap.size()>k)
        {
            min_heap.pop();
        }
    }
    return min_heap.top();
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
     for(int i = 0; i<n;i++)
     {
        cin>>nums[i];
     }
    
    cout<<solve(nums,k)<<endl;
    }
    return 0;
}