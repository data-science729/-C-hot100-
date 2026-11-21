/**
 * ============================================================================
 * 【题目名称】二叉树最大宽度
 * ============================================================================
 *
 * 【题目描述】
 *   给定一棵二叉树，求它的最大宽度。
 *   - 最大宽度：所有层中最大的宽度。
 *   - 每一层的宽度定义为该层最左和最右非空节点（两个端点）之间的长度。
 *     将二叉树视作与满二叉树结构相同，两端点之间延伸到这一层的 null 节点
 *     也计入长度。
 *   - 序列表示：层序序列。首项为根节点，随后对每个非空节点依次读取其左、右
 *     孩子（null 表示为空）。序列末尾不影响树结构的连续 null 已省略。
 *
 * 【输入格式】
 *   第一行：整数 k，表示层序序列的标记数量。
 *   第二行：k 个空格分隔的标记（整数或 null），首项必为整数。
 *
 * 【输出格式】
 *   输出一个整数，表示二叉树的最大宽度。
 *
 * 【数据范围】
 *   1 <= 节点总数 <= 3000，-100 <= 节点值 <= 100，1 <= k <= 2n + 1
 *   题目数据保证答案在 32 位带符号整数范围内。
 *
 * 【样例】
 *   输入 1：
 *     7
 *     1 3 2 5 3 null 9
 *   输出 1：
 *     4
 *
 *   输入 2：
 *     9
 *     1 3 2 5 null null 9 6 null 7
 *   输出 2：
 *     7
 *
 *   输入 3：
 *     4
 *     1 3 2 5
 *   输出 3：
 *     2
 * ============================================================================
 */
#include <bits/stdc++.h>
using namespace std;
// 1. 数据结构定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// 2. 非核心辅助：层序建树
TreeNode* buildTree(const vector<string>& tok) {
    int k = tok.size();
    if (k == 0) return nullptr;
    TreeNode* root = new TreeNode(stoi(tok[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < k && !q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < k) {
            if (tok[i] != "null") {
                node->left = new TreeNode(stoi(tok[i]));
                q.push(node->left);
            }
            i++;
        }
        if (i < k) {
            if (tok[i] != "null") {
                node->right = new TreeNode(stoi(tok[i]));
                q.push(node->right);
            }
            i++;
        }
    }
    return root;
}

//核心算法:BFS + 每层归零防溢出的位置编号
int maxWidth(TreeNode* root)
{
    //1.处理空树+初始化队列
    if(root == nullptr)  return 0;   //空树宽度为0
    queue<pair<TreeNode*,unsigned long long>> q; //同时保存节点地址和完全二叉树下标
    q.push({root,1}); //根节点编号为1
    int ans = 0;  //记录所有层中的最大宽度
    //2.建立BFS主循环
    while(!q.empty())
    {
        int sz = q.size();
        //3.记录当前层左右端点 .first是节点指针 .second是节点下标
        unsigned long long L = q.front().second;
        unsigned long long R = L;  //R暂时初始化为L 后续再遍历中不断更新
        //4.遍历当前层
        for(int i = 0 ;i<sz;i++)
        {
        auto[node,idx] = q.front(); //结构化绑定 相当于TreeNode* node = q.front().first; unsigned long long idx = q.front().second;
        q.pop();
        //5.更新右端点 添加左右孩子
        R = idx ; 
        if(node->left != nullptr)  q.push({node->left,2*idx});
        if(node->right != nullptr) q.push({node->right,2*idx +1});
        }
        ans = max(ans,(int)(R-L+1));
    }
    return ans;
}