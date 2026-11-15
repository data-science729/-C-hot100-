/**
 * 240. 搜索二维矩阵 II
 * 难度：中等
 * 
 * 【题目描述】
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * - 每行的元素从左到右升序排列。
 * - 每列的元素从上到下升序排列。
 * 
 * 【示例 1】
 * 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * 输出：true
 * 
 * 【示例 2】
 * 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
 * 输出：false
 * 
 * 【提示】
 * - m == matrix.length
 * - n == matrix[i].length
 * - 1 <= n, m <= 300
 * - -10^9 <= matrix[i][j] <= 10^9
 * - 每行的所有元素从左到右升序排列
 * - 每列的所有元素从上到下升序排列
 * - -10^9 <= target <= 10^9
 */
#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<int>>& matrix,int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int i = 0; //行指针:从第0行开始
    int j = n-1; //列指针:从第(n-1)列开始
    //合法行下标最大是(m-1) 因此是i<m
    while(i<m && j>=0)
    {
      if(matrix[i][j] == target)
      {
        return true;
      }
      else if(matrix[i][j]>target)
      {
        j--;
      }
      else
      {
        i++;
      }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m ,n;
    while(cin>>m>>n)
    {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }
        int target;
        cin>>target;
        bool flag = solve(matrix,target);
        cout<<(flag?"true":"false")<<"\n";
    }
    return 0;
}
