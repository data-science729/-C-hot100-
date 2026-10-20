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

//二分:利用每一行都是升序数组 没必要逐个检查每个元素
//可以对每一行进行二分查找
bool solve(vector<vector<int>>& matrix,int target)
{
   int m = matrix.size();
   int n = matrix[0].size();
   for(int i = 0;i<m;i++)   // 外层：一共遍历 m 行
   {
    int left = 0;
    int right = n-1;
    while(left<=right)   // 内层：对当前行（长度为 n）进行二分查找
    {
        //这种mid写法就是数学上等价的向下取整的中间位置
        int mid = left + (right-left)/2;
        if(matrix[i][mid]==target)
        {
            return true;
        }
        else if(matrix[i][mid]<target)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
   }
   return false;
}

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     //必须先读m和n 读入完整矩阵 最后再读target
     int m,n;
     while(cin>>m>>n)
     {
        if(m<=0||n<=0)  continue;
        vector<vector<int>> matrix(m,vector<int>(n,0));
        //读取完整的矩阵内容
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }
        //矩阵读完后 最后单独读取目标值target
        int target;
        cin>>target;
        //调用求解并输出true/false 
        bool flag = solve(matrix,target);
        cout<<(flag?"true":"false")<<"\n";
     }
     return 0 ;
    }