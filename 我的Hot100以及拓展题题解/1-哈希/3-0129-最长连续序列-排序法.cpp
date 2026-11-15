/*
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 示例 1：
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 示例 3：
 * 输入：nums = [1,0,1,2]
 * 输出：3
 * 
 * 提示：
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 */

 #include<iostream>
 #include<unordered_map>
 #include<algorithm>
 #include<vector>
using namespace std;

int solve(vector<int>& nums)
{
    if(nums.empty()) return 0;
    sort(nums.begin(),nums.end());  //STL快排 O(nlogn)
    //双变量模式 max保存全局状态 cur保存局部状态
    int maxlen = 1;
    int curlen = 1;
    
    for(int i = 1;i<nums.size();i++)
    {
       //去重 相同的数不增加连续长度 不中断连续型
       if(nums[i] == nums[i-1])
       {
        continue;
       } 

       //严格递增1的判定
       if(nums[i] == nums[i-1]+1)
       {
         curlen++;
       }
       else
       {
        curlen = 1; // 连续性中断 重置计数器
       }
        maxlen = max(curlen,maxlen); 
 //我们不需要具体去对maxlen做什么操作 只需要其能够保存到max(curlen),它的作用就显现出来了
    }
    return maxlen;
}
int main()
{
    // 1. ACM 标配：正确调用函数，关闭流同步
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        // 加上 continue 防止重复输出
        if (n == 0)
        {
            cout << 0 << endl;
            continue; 
        }

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << solve(nums) << endl;
    }
    
    return 0;
}


    



    



