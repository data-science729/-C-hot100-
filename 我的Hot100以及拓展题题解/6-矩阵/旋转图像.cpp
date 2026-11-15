/**
 * 48. 旋转图像
 * 难度：中等
 * 
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 示例 1：
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 示例 2：
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 提示：
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>>& matrix)
{
    int m = matrix.size(); //必然为方阵
    
    //1.转置矩阵
    for(int i = 0;i<m;i++)
    {
        for(int j = i+1;j<m;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //2.每一行左右翻转
    for(int i = 0;i<m;i++)
    {
        for(int j =0;j<m/2;j++)
        {
            swap(matrix[i][j],matrix[i][m-1-j]);
        }
    }
    return matrix;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int m;
   while(cin>>m)
   {
    vector<vector<int>> matrix(m,vector<int>(m,0));
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> ans = solve(matrix);
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<m;j++)
        {
            //核心:第一个元素前不输出空格，后续元素前先输出一个空格
            if(j>0)  cout<<' ';
            cout<<ans[i][j];
        }
        //内层循环外:每行结束后输出换行符'\n'
        cout<<'\n';
    }
}
return 0;
}