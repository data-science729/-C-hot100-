/*
 * 200. 岛屿数量
 * 难度：中等
 * 相关标签：深度优先搜索、广度优先搜索、并查集、数组、矩阵
 * 
 * 题目描述：
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 示例 1：
 * 输入：grid = [
 *   ['1','1','1','1','0'],
 *   ['1','1','0','1','0'],
 *   ['1','1','0','0','0'],
 *   ['0','0','0','0','0']
 * ]
 * 输出：1
 * 
 * 示例 2：
 * 输入：grid = [
 *   ['1','1','0','0','0'],
 *   ['1','1','0','0','0'],
 *   ['0','0','1','0','0'],
 *   ['0','0','0','1','1']
 * ]
 * 输出：3
 * 
 * 提示：
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 300
 * - grid[i][j] 的值为 '0' 或 '1'
 */
#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1,1,0,0};  //方向辅助:上下左右
const int dy[4] = {0,0,-1,1};  

int m,n ; //行数和列数定义为全局变量 将函数传参的微小开销都省掉

//微观探路:网格DFS 
//任务:将与(r,c)相连的整块陆地全部变成水('0')
void dfsGrid(vector<vector<char>>& grid,int r,int c)
{
    //递归出口:越界 或者 当前是水('0')
    if(r<0||r>=m||c<0||c>=n||grid[r][c] == '0')
    {
        return;
    }
    //核心动作:原地打卡 沉岛，把陆地变成水，防止后续重复访问死循环（发现一座 当场消灭一座)
    grid[r][c] = '0' ;

    //顺着上下左右4个方向深探
    for(int i = 0;i<4;++i)
    {
        dfsGrid(grid,r+dx[i],c+dy[i]);
    }
}

int solve(vector<vector<char>>& grid)
{
  if(grid.empty()||grid[0].empty())  return 0;
  int m = grid.size();    //row 行数
  int n = grid[0].size();  //column 列数
  int islands = 0 ;
  //双重循环 雷达扫描从左上角到右下角的每一个格子
  for(int i = 0;i<m;++i)
  {
    for(int j = 0 ;j<n;++j)
    {
        //只要发现一块还没被沉没的陆地
      if(grid[i][j] == '1')
      {
        islands++; //岛屿总数+1

        //呼叫dfs 从(i,j)开始把与它相连的整块大岛全部变成水'0'
        dfsGrid(grid,i,j);
      }
    }
}
return islands ; 
}
  

  


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    while(cin>>m>>n)
    {
      //创建大小为m*n的二维字符网格
      vector<vector<char>> grid(m,vector<char>(n));

      //双重循环读入每一个字符
      for(int i = 0 ; i<m ; ++i)
      {
        for(int j = 0 ;j<n ;++j)
        {
            cin>>grid[i][j];
        }
      }
      int ans = solve(grid);
      cout<<ans<<'\n';
    }
    return 0;
}


