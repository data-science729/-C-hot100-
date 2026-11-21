/**
 * ============================================================================
 * 【题目名称】二叉树中叶子结点个数
 * ============================================================================
 *
 * 【题目描述】
 *   给定一棵二叉树，求其中叶子结点的个数。
 *   - 叶子结点：度为 0 的结点，即左孩子和右孩子均为空（nullptr）的结点。
 *     （空树叶子结点个数为 0；仅包含一个根结点的树叶子结点个数为 1。）
 *   - 序列表示：层序序列。首项为根结点，随后对每个非空结点依次读取其左、右
 *     孩子（null 表示为空）。序列末尾不影响树结构的连续空结点已省略；空树长度 0。
 *
 * 【输入格式】
 *   第一行：整数 k，表示层序序列的标记数量。
 *   第二行（当 k > 0 时）：k 个空格分隔的标记（整数或 null），首项必为整数。
 *
 * 【输出格式】
 *   输出一个整数，表示二叉树中叶子结点的个数。
 *
 * 【数据范围】
 *   0 <= n <= 10^4, -100 <= 结点值 <= 100, 0 <= k <= 2n + 1
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

int countLeaves(TreeNode* root)
{
    if(root == nullptr)  return 0; //出口1:空结点
    if(root->left == nullptr && root->right == nullptr) return 1; //出口2:自己是叶子结点返回1
    int leftLeaves = countLeaves(root->left);
    int rightLeaves = countLeaves(root->right);
    return leftLeaves + rightLeaves;  
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    while (cin >> k)
    {
        vector<string> tok(k);
        for (int i = 0; i < k; ++i)
        {
            cin >> tok[i];
        }

        TreeNode* root = buildTree(tok);
        cout << countLeaves(root) << '\n';
    }
    return 0;
}
