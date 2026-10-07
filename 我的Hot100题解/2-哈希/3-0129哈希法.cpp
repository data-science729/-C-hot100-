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
 #include<unordered_set>
 #include<algorithm>
 #include<vector>
using namespace std;

int solve(const vector<int>& nums)
{
    if(nums.empty())   return 0;
    //将所有数字装入哈希集合,自动去重 查询O(1)
    unordered_set<int> numset(nums.begin(),nums.end());
    int maxlen = 0;
    for(int num : numset)
    {
        //只寻找排头兵 判断num是不是起点 看num-1在不在集合里 如果在，说明num不是排头兵直接跳过，否则是起点
        if(numset.find(num-1) == numset.end())
        {
            int curNum = num;
            int curLen = 1;
            //从起点开始 顺藤摸瓜往后数
            while(numset.find(curNum+1)!=numset.end())
            {
                curNum++;
                curLen++;
            }
            maxlen = max(curLen,maxlen);
        }
        
    }
    return maxlen;
}

int main()
{
     // ACM 快速 I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << solve(nums) << endl;
    }
    return 0;
}
