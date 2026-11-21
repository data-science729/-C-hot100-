/**
 * ============================================================================
 * 【题目名称】二叉树最大深度
 * ============================================================================
 *
 * 【题目描述】
 *   给定一棵二叉树，求它的最大深度。
 *   - 最大深度：从根节点到最远叶子节点的最长路径上的节点数（空树为 0）。
 *   - 序列表示：层序序列。首项为根节点，随后对每个非空节点依次读取其左、右
 *     孩子（空节点表示为空）。序列末尾不影响树结构的连续空节点已省略；空树长度 0。
 *
 * 【输入格式】
 *   第一行：整数 k，表示层序序列的标记数量。
 *   第二行（当 k > 0 时）：k 个空格分隔的标记（整数或空节点），首项必为整数。
 *
 * 【输出格式】
 *   输出一个整数，表示二叉树的最大深度。
 *
 * 【数据范围】
 *   0 <= n <= 10^4, -100 <= 节点值 <= 100, 0 <= k <= 2n + 1
 *
 * 【样例】
 *   输入：
 *     7
 *     3 9 20 null null 15 7
 *   输出：
 *     3
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

int maxDepth(TreeNode* root)
{
    if(root == nullptr)  return 0;  //出口:空节点深度为0
    int leftDepth = maxDepth(root->left); //算左子树最大深度
    int rightDepth = maxDepth(root->right); //算右子树最大深度
    return max(leftDepth,rightDepth) + 1; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    while(cin>>k)
    {
        vector<string> tok(k);
        for(int i = 0;i<k;++i)
        {
            cin>>tok[i];
        }
        TreeNode* root = buildTree(tok);
        cout<<maxDepth(root)<<'\n';
    }
    return 0;
}