/*
 * LeetCode 283. 移动零 (Move Zeroes)
 *
 * 题目描述:
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 请注意，必须在不复制数组的情况下原地对数组进行操作。
 *
 * 示例 1:
 *     输入: nums = [0, 1, 0, 3, 12]
 *     输出: [1, 3, 12, 0, 0]
 *
 * 示例 2:
 *     输入: nums = [0]
 *     输出: [0]
 *
 * 提示:
 *     1 <= nums.length <= 10^4
 *     -2^31 <= nums[i] <= 2^31 - 1
 *
 * 进阶:
 *     你能尽量减少完成的操作次数吗？
 */

 #include<bits/stdc++.h>
 using namespace std;

void solve(vector<int>& nums)
{
    int slow = 0;
    for(int fast = 0;fast<nums.size();fast++)
    {
        if(nums[fast]!=0)
        {
            //这一个if是用来极限压榨性能的 防止自己跟自己交换
            if(slow!=fast)
            {
                swap(nums[slow],nums[fast]);
            }
            slow++;
        }
    }

}




 int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
    {
      if(n==0)
      {
        cout<<0<<endl;
        continue;
      }
      vector<int> nums(n);
      for(int i=0;i<n;i++)
      {
        cin>>nums[i];
      }
      solve(nums);
      for(int i = 0;i<n;i++)
      {
        cout<<nums[i]<<(i==n-1? "":" ");
      }
      cout<<endl;
    }
    return 0;
}
