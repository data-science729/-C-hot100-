/*
 * 73. 矩阵置零
 * 难度：中等
 *
 * 题目描述：
 * 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。
 * 请使用 原地 算法。
 *
 * 示例 1：
 * 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：[[1,0,1],[0,0,0],[1,0,1]]
 *
 * 示例 2：
 * 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 *
 * 提示：
 * - m == matrix.length
 * - n == matrix[0].length
 * - 1 <= m, n <= 200
 * - -2^31 <= matrix[i][j] <= 2^31 - 1
 *
 * 进阶：
 * - 一个直观的解决方案是使用 O(mn) 的额外空间，但这并不是一个好的解决方案。
 * - 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * - 你能想出一个仅使用常量空间的解决方案吗？
 */
#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>& matrix)
{
    if(matrix.empty()||matrix[0].empty())  return ;
    int m  = matrix.size();
    int n = matrix[0].size();
    //1.创建原矩阵的深拷贝副本 隔离历史状态
    vector<vector<int>> copy = matrix;
    //2.在副本上检查原始的0，并在原矩阵中执行置零
    for(int i = 0;i<m;++i)
    {
        for(int j = 0;j<n;++j)
        {
            if(copy[i][j] == 0)
            {
                //将原矩阵第i行全部置为0
                for(int c = 0;c<n;++c)
                {
                    matrix[i][c] = 0;
                }
                //将原矩阵第j列全部置为0
                for(int r = 0;r<m;++r)
                {
                    matrix[r][j] = 0;
                }
            }
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);
   int m,n;
   while(cin>>m>>n)
   {
    //边界条件防御
    if(m<=0 || n<=0) 
    {
        continue;
    }
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i = 0;i<m;++i)
    {
        for(int j =0;j<n;++j)
        {
            cin>>matrix[i][j];
        }
    }
    //调用解法
    solve(matrix);
    //输出置零后的矩阵
    for(int i = 0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<matrix[i][j]<<(j==n-1?"":" ");
        }
        cout<<"\n";
    }
   }
   return 0;
}