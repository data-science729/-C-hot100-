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

vector<int> solve(const vector<int>& nums,int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq ; //单调双端队列 存下标 值单调递减
    for(int i = 0;i<n;++i)
    {
        //1.队头出队 检查队头下标是否滑出滑动窗口边界[i-k+1,i]
        if(!dq.empty() && dq.front()<=i-k)
        {
           dq.pop_front();
        }
        //2.队尾淘汰:当前元素比队尾大或者相等 队尾元素永无出头之日 直接淘汰
        while(!dq.empty() && nums[dq.back()]<=nums[i])
        {
            dq.pop_back();
        }
        //3.新人入队 将当前元素下标压入队尾
        dq.push_back(i);
        //4.记录答案 当窗口成型(i>=k+1)时 队头就是最大值
        if(i>=k-1)
        {
            ans.push_back(nums[dq.front()]);
        }

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
        for(int i = 0 ;i<n;++i)
        {
            cin>>nums[i];
        }
        vector<int> ans = solve(nums,k);
        for(int i = 0;i<(int)ans.size();++i)
        {
            cout<<ans[i]<<(i == (int)ans.size()-1?"":" ");
        }
      cout<<"\n";
    }
    return 0;
}