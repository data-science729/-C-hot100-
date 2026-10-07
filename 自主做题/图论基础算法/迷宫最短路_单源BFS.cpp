/*
 * 迷宫最短路径（走迷宫问题 - 单源 BFS 经典母题）
 * 难度：中等 / 经典普及
 * 相关标签：广度优先搜索 (BFS)、队列 (Queue)、最短路径、网格图
 * 
 * 题目描述：
 * 给定一个大小为 m x n 的二维网格迷宫 grid 。
 * - 网格中的值 0 代表空地，可以自由通行；
 * - 网格中的值 1 代表障碍物（墙壁），不可通行。
 * 
 * 初始时，你位于迷宫的左上角起点 (0, 0) ，目标是走到右下角的终点 (m - 1, n - 1) 。
 * 移动规则：每一步你只能向 水平或者垂直的四个方向（上、下、左、右）移动到相邻的空地格子。
 * 
 * 请你计算并返回从起点 (0, 0) 到终点 (m - 1, n - 1) 所需经过的【最少移动步数】。
 * 如果由于障碍物阻挡无法到达终点，则返回 -1 。
 * 
 * 示例 1：
 * 输入：
 * 5 5
 * 0 1 0 0 0
 * 0 1 0 1 0
 * 0 0 0 0 0
 * 0 1 1 1 0
 * 0 0 0 1 0
 * 输出：
 * 8
 * 解释：
 * 最短路线之一为：
 * (0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2) -> (2,3) -> (2,4) -> (3,4) -> (4,4)
 * 共计移动 8 步。
 * 
 * 示例 2：
 * 输入：
 * 3 3
 * 0 1 0
 * 1 1 0
 * 0 0 0
 * 输出：
 * -1
 * 解释：起点 (0,0) 周围全是障碍物(1)，无法前往终点，故返回 -1 。
 * 
 * 示例 3：
 * 输入：
 * 1 1
 * 0
 * 输出：
 * 0
 * 解释：起点本身就是终点，步数为 0 。
 * 
 * 提示：
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 100
 * - grid[i][j] 的值为 0 或 1
 * - 起点为 (0, 0)，终点为 (m - 1, n - 1)
 * - 如果起点 grid[0][0] == 1 或终点 grid[m-1][n-1] == 1，直接返回 -1。
 */
#include<bits/stdc++.h>
using namespace std;

const int dr[4] = {-1,1,0,0};
const int dc[4]= {0,0,-1,1};

//单源BFS核心寻路函数
int bfsMaze(vector<vector<int>>& grid)
{
    if(grid.empty()||grid[0].empty())  return -1;
    int m = grid.size() ;
    int n = grid[0].size();
    //防御性特判:起点或终点本身就是墙,绝对不可能到达终点 直接判死刑 返回-1
    if(grid[0][0] ==1||grid[m-1][n-1] == 1)  return -1 ;
    //起点本身就是终点 0步直接到达
    if(m ==1 && n==1)  return 0 ;

    queue<pair<int,int>> q ; //创建先进先出队列 存放待扩散的坐标(r,c)
    //单源起点入队 放入起点并立即原地打卡
    q.push({0,0}) ;
    grid[0][0] = 1;
    int steps = 0 ; //记录水波扩散的圈数(移动步数)

    //水波一圈一圈向外扩散
    while(!q.empty())
    {
         int sz = q.size() ; //快照截断:记录当前这一圈有多少个节点
         //齐头并进处理这一圈的所有节点
         for(int i = 0 ; i<sz; ++i)
         {
          auto[r,c] = q.front();
          q.pop();
          //第一次抵达右下角终点 当前steps必然是最短步数
          if(r == m-1 && c == n-1)
          {
            return steps ;
          }
          //向上下左右四个方向探索邻居
          for(int d = 0 ;d<4 ;d++)
          {
            int nr = r+dr[d];
            int nc = c+dc[d];
            //边界与障碍检查 未越界 且 是可以走的空地(0)
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 0)
            {
                grid[nr][nc] = 1 ; //入队瞬间立即打卡
                q.push({nr,nc}) ; //加入下一圈的待扩展队列
            }
          }
         }
         //整整一圈全部处理完毕 步数+1
         steps++;
    }
    return -1 ; //队列探空了也没有碰到终点 说明死路一条
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr) ; 
    int m ,n ;
    while(cin>>m>>n)
    {
        vector<vector<int>> grid(m,vector<int>(n)) ; 
        for(int i = 0 ;i<m;++i)
        {
            for(int j = 0 ;j<n;++j)
            {
                cin>>grid[i][j];
            }
        }
        cout<<bfsMaze(grid)<<'\n' ;
    }
    return 0 ;
}







