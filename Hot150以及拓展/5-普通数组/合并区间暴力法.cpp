/*
 * ==============================================================================
 * 56. 合并区间
 * 难度：中等
 * 
 * 题目描述：
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
 * 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 * 
 * 示例 1：
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 示例 2：
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 示例 3：
 * 输入：intervals = [[4,7],[1,4]]
 * 输出：[[1,7]]
 * 解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。
 * 
 * 提示：
 * - 1 <= intervals.length <= 10^4
 * - intervals[i].length == 2
 * - 0 <= starti <= endi <= 10^4
 * ==============================================================================
 */
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& intervals)
{
   //true:本轮扫描发生了合并 false:本轮扫描尚未发生合并
   //一开始设置为true：条件为真才进入while循环 为了让算法至少执行一轮扫描
   bool changed = true; 
   while(changed)
   {
    //先假设这一轮没有任何区间能够合并 通过扫描 看能不能打脸
      changed = false;
      for(int i = 0;i<intervals.size();i++)
      {
        for(int j = i+1;j<intervals.size();j++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = intervals[j][0];
            int d = intervals[j][1];
            //判断是否重叠
            if(a<=d && c<=b)
            {
                //合并到第i个区间
                intervals[i][0] = min(a,c);
                intervals[i][1] = max(b,d);
                //删除第j个区间
                //erase()会改变vector的大小以及部分元素的下标
                intervals.erase(intervals.begin()+j);
                changed = true;
                break; //后面所有j都不用看了 每合并一次就重新扫描
            }
        }
        if(changed) break;
      }
   }
   return intervals;
}


//读取n->读取二维数组->调用solve()->输出结果
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
    {
        vector<vector<int>> intervals(n,vector<int>(2));
        //输入每个区间
        for(int i = 0;i<n;i++)
        {
            cin>>intervals[i][0]>>intervals[i][1];
        }
        vector<vector<int>> ans = solve(intervals);
        //范围for循环 建议用单数interval或item 避免与外层变量重名
        for(auto &interval : ans)
        {
            cout<<interval[0]<<" "<<interval[1]<<"\n";
        }
    }

}