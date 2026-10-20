/**
 * 54. 螺旋矩阵
 * 
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 示例 1：
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 示例 2：
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 提示：
 * - m == matrix.length
 * - n == matrix[i].length
 * - 1 <= m, n <= 10
 * - -100 <= matrix[i][j] <= 100
 */
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<vector<int>>& matrix)
{
    int m = matrix.size();

    // 防止空矩阵访问 matrix[0] 越界
    if (m == 0) return {};

    int n = matrix[0].size();

    // 定义四个边界变量
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    vector<int> ans;
    ans.reserve(m * n);

    // 只要仍然存在未遍历的行和列，就继续遍历
    while (top <= bottom && left <= right)
    {
        // 1. 向右：遍历最上面一行，left -> right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // 2. 向下：遍历最右边一列，top -> bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // 3. 向左：遍历最下面一行，right -> left
        // 必须保证仍然存在未遍历的行
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // 4. 向上：遍历最左边一列，bottom -> top
        // 必须保证仍然存在未遍历的列
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}
    


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    while(cin>>m>>n)
    {
        vector<vector<int>> matrix(m,vector<int>(n,0));//初始化全为0
        //完整读取矩阵的每个元素
        for(int i = 0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }
        vector<int> ans = solve(matrix);
        for(int i = 0;i<ans.size();i++)
        {
            cout<<ans[i]<<(i==ans.size()-1?"":" ");
        }
        cout<<"\n";
    }
    return 0;
}