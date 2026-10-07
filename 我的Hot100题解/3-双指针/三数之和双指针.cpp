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
#include <bits/stdc++.h>
using namespace std;

// 1. 去掉 const，允许原地排序
vector<vector<int>> solve(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    if (n < 3) return ans;

    // 1. 排序
    sort(nums.begin(), nums.end());
    
    // 2. 固定第一个数
    for (int i = 0; i < n; i++)
    {
        // 剪枝：若排头数已大于0，后续相加不可能为0
        if (nums[i] > 0) break;

        // 第一个数去重
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        // 左右双指针
        int l = i + 1;
        int r = n - 1;

        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];

            // 1. 和太小，左指针右移
            if (sum < 0)
            {
                l++;
            }
            // 2. 和太大，右指针左移（修复：改成 r-- 与 else if）
            else if (sum > 0)
            {
                r--;
            }
            else
            {
                // 3. 记录解
                ans.push_back({nums[i], nums[l], nums[r]});

                // 跳过连续重复的元素
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;

                // 指针各向内走一步
                l++;
                r--;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
   

    int n;
    while (cin >> n)
    {
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        vector<vector<int>> res = solve(nums);

        // 修复：标准二维数组打印格式，使用 res.size() 防越界
        cout << "[";
        for (size_t i = 0; i < res.size(); i++)
        {
            cout << "[" << res[i][0] << "," << res[i][1] << "," << res[i][2] << "]";
            if (i + 1 < res.size()) cout << ",";
        }
        cout << "]\n"; // 修复：每组测试用例内部闭合括号并换行
    }
    return 0;
}