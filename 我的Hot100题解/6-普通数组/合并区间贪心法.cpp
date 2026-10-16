/*
 * ==============================================================================
 * 56. 合并区间 - 排序贪心法
 * 时间复杂度：O(n log n)
 * 空间复杂度：O(log n) 或 O(n)（存储答案）
 * ==============================================================================
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& intervals)
{
    if (intervals.empty()) return {};

    // 1. 按照左端点升序排序
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> ans;

    // 2. 初始化当前维护的区间 [L, R] 为第 0 个区间
    int L = intervals[0][0];
    int R = intervals[0][1];

    // 3. 从第二个区间开始进行扫描
    for (int i = 1; i < (int)intervals.size(); i++)
    {
        int a = intervals[i][0];
        int b = intervals[i][1];

        // 存在重叠：当前区间左端点 <= 当前维护的右端点，扩张右端点
        if (a <= R)
        {
            R = max(R, b);
        }
        // 不存在重叠：前面的区间可以最终确定
        else
        {
            ans.push_back({L, R});
            // 开启维护下一个区间 因为虽然没和前边的[L,R]区间何冰 但可能会和后面的雪块合并
            //要返回的是vector<vector<int>> 而非一个[L,R]
            L = a;
            R = b;
        }
    }

    // 4. 【关键修复 1】循环结束后，必须将最后维护的一组区间存入 ans
    ans.push_back({L, R});

    // 5. 【关键修复 2】返回合并后的结果
    return ans;
}

int main()
{
    // ACM 快速 I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> intervals[i][0] >> intervals[i][1];
        }

        vector<vector<int>> ans = solve(intervals);

        for (const auto &interval : ans)
        {
            cout << interval[0] << " " << interval[1] << "\n";
        }
    }
    return 0;
}