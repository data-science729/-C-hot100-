/*
 * 题目名称：逃离迷宫 (HDU 1728)
 * 限制要求：Time Limit: 1000/1000 MS (Java/Others)  Memory Limit: 32768/32768 K (Java/Others)
 * 
 * 题目描述：
 *   给定一个 m × n (m行, n列) 的迷宫，迷宫中有两个位置，gloria想从迷宫的一个位置走到另外一个位置。
 *   迷宫中 '.' 表示空地，'*' 表示障碍。每次只能移动到上下左右相邻的4个位置之一，且不能走出迷宫边界。
 *   gloria在行走过程中不能转太多弯（最多转弯 k 次）。
 *   起点和终点均保证为空地；初始时 gloria 面向方向未定，选择初始出发方向不算转弯。
 *   问 gloria 是否能在转弯次数不超过 k 的情况下从起点走到终点。
 * 
 * 输入格式：
 *   第 1 行输入一个整数 t (1 ≤ t ≤ 100)，表示测试数据组数。
 *   每组测试数据格式如下：
 *     - 第 1 行输入两个整数 m, n (1 ≤ m, n ≤ 100)，分别表示迷宫的行数和列数。
 *     - 接下来 m 行，每行包含 n 个字符（'.' 表示空地，'*' 表示障碍）。
 *     - 最后一行包含 5 个整数 k, x1, y1, x2, y2：
 *         k (1 ≤ k ≤ 10)：最多允许转弯的次数；
 *         (x1, y1)：起点坐标，其中 x1 对应列，y1 对应行；
 *         (x2, y2)：终点坐标，其中 x2 对应列，y2 对应行。
 * 
 * 输出格式：
 *   每组数据输出一行：若能到达输出 "yes"，否则输出 "no"。
 * 
 * 样例输入：
 *   2
 *   5 5
 *   ...**
 *   *.**.
 *   .....
 *   .....
 *   *....
 *   1 1 1 1 3
 *   5 5
 *   ...**
 *   *.**.
 *   .....
 *   .....
 *   *....
 *   2 1 1 1 3
 * 
 * 样例输出：
 *   no
 *   yes
 * 
 * 注意事项：
 *   坐标给定形式为 (x, y) 对应 (列, 行)，在二维数组映射时需注意对应关系为 grid[y][x]。
 */

//升级点1(优化目标):沿直线走代价为0 转弯才有1的代价 起始时可以选择4个方向任何一个出发而不算成一次转弯
//升级点2:扩散动作:站在(r,c) 选定一个方向d后 启动一个while循环 像激光一样直接射穿整条走廊 直到撞墙或者出界
//升级点3:队列分层的物理含义改变 每一层代表转了第几次弯 要在层数<=k时碰到终点才输出yes
//升级点4:打卡防死循环的机制变了 不能随便将格子焊死
//做法:维护一个每个格子历史被访问时的"最小转弯次数" 维护vector<vector<int>> min_turns(m,vector<int>(n,INT_MAX))
//升级点5:下标从1开始
#include<bits/stdc++.h>
using namespace std;
const int dr[4] = {-1,1,0,0};
const int dc[4] = {0,0,-1,1};

bool bfs(vector<string>& grid,pair<int,int> start,pair<int,int> target,int k)
{
    int m = grid.size();  int n = grid[0].size();
    auto[sr,sc] = start;  auto[tr,tc] = target;
    if(grid[sr][sc] == '*'||grid[tr][tc] == '*')  return false;
    if(sr == tr && sc == tc)  return true;
    //队列里装的是坐标位置(行号和列号) 因而是pair<int,int>
    queue<pair<int,int>> q;
    q.push({sr,sc});
    
    vector<vector<int>> min_turns(m,vector<int>(n,INT_MAX));
    min_turns[sr][sc] = 0 ;
    int turns = 0;
 
    while(!q.empty())
    {
       
        //如果当前转弯值超过允许的最大值k 直接退出判false
        if(turns>k)  return false;
        int sz = q.size();
        //快照 记录这一圈的节点总数
        for(int i = 0 ;i<sz;++i)
        {
            auto[r,c] = q.front();
            q.pop();
            
            //依次向四个方向发射激光
            for(int d = 0 ;d<4;++d)
            {
                int nr = r+dr[d];
                int nc = c+dc[d];
                //启动while循环 只要是空地'.',激光就一路向前穿透到底
                while(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] =='.')
            {
                //如果激光直接命中了终点 大功告成
                if(nr == tr && nc == tc)
                {
                    return true;
                }
                //记忆化打卡 记录到达(nr,nc)的最小转弯数
                //在(r,c)这个点 已经转了turns次弯-->现在是没直接到终点的情况
                //因此激光需要转一次弯-->(nr,nc)这个点 转turns+1次弯
                //这个if作用就是打擂台，比较每一次情况
                if(min_turns[nr][nc]>turns + 1)
                {
                  min_turns[nr][nc] = turns+1;
                  q.push({nr,nc});
                }
                nr+=dr[d];
                nc+=dc[d];

            }
            
            }
           

        }
        turns++; //一圈探索完毕
    }
    return false; //找空了都没能到达终点
}





//多重包裹结构 最外层是总测试用例组数t 读入的的网格是字符. *
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //第一层 读入总测试数据组数t
    int t;
    if(cin>>t)
    {
        //循环t次 每次处理一组独立的迷宫
        while(t--)
        {
         int m,n;
         cin>>m>>n ; //输入行数和列数
         //第二层:输入m行字符网格 推荐用vector<string>,读每一行就像读一个单词一样丝滑
         vector<string> grid(m);
         for(int i = 0;i<m;++i)
         {
            cin>>grid[i];
         }
         //第三层 读入最后一行 5个核心参数 转弯数 起点坐标 终点坐标
         int k,x1,y1,x2,y2;
         cin>>k>>x1>>y1>>x2>>y2;
         //陷阱：坐标转换 x对应列 y对应行 且从1开始
         int sr = y1-1;
         int sc = x1-1;
         int tr = y2-1;
         int tc = x2-1;

         //第四层：调用bfs寻路算法输出结果
         if(bfs(grid,{sr,sc},{tr,tc},k))
         {
            cout<<"yes\n";
         }
         else
         {
            cout<<"no\n";
         }
        }
    }
    return 0;
}
    
   
    

