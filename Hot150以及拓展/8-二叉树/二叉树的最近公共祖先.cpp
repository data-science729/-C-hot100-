/*
 * ============================================================
 *  题目：二叉树的最近公共祖先（LeetCode 236）
 *  来源：pgcode.cn · 力扣 Hot100 考研机试真题
 * ============================================================
 *
 *  【题目描述】
 *    给定一棵二叉树以及树中的两个结点 p, q，求它们的最近公共祖先。
 *    一个结点可以是它自己的祖先，树中结点值互不相同。
 *
 *  【输入格式】
 *    第一行：输入整数 n，表示随后层序序列中的记号数。
 *
 *    第二行：输入 n 个以空格分隔的记号，按层序表示二叉树。
 *            整数表示结点值，null 表示空孩子；
 *            序列仅保留到最后一个非空结点为止。
 *
 *    第三行：输入两个整数 p, q，表示待查询结点的值。
 *
 *  【输出格式】
 *    输出最近公共祖先的结点值。
 *
 *  【数据范围】
 *    树中结点数满足 2 ≤ m ≤ 10^5
 *    -10^9 ≤ val ≤ 10^9
 *    所有结点值互不相同，p 和 q 均存在于树中且 p ≠ q
 *
 *  【输入样例】
 *    11
 *    3 5 1 6 2 0 8 null null 7 4
 *    5 1
 *
 *  【输出样例】
 *    3
 *
 *  【核心考点】
 *    1. 根据带 null 的层序序列构建二叉树（结点值含负数，需按字符串读入）。
 *    2. 后序递归（自底向上回溯）求二叉树最近公共祖先（LCA）。
 *
 * ============================================================
 */
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
   int val;
   TreeNode* left; 
   TreeNode* right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

   TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

TreeNode* buildTree(const vector<string>& tok)
{
    int k = tok.size();
    if(k == 0 || tok[0] == "null")  return nullptr;
    TreeNode* root = new TreeNode(stoi(tok[0]));
    queue<TreeNode*> q;
    q.push(root); int i =1;
    while(i<k && !q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(i<k)
        {
            if(tok[i]!="null")
            {
                node->left = new TreeNode(stoi(tok[i]));
                q.push(node->left);
            }
            i++;
        }
        if(i<k)
        {
            if(tok[i]!="null")
            {
                node->right = new TreeNode(stoi(tok[i]));
                q.push(node->right);
            }
            i++;
        }
    }
   return root;
}
//左右根:用的后序遍历
//含义:在以root为根的子树中 寻找p和q的最近公共祖先 并返回该节点的指针
//因为是递归 必须要TreeNode*类型 方便上一层继续判断 而非只返回节点值
TreeNode* findLCA(TreeNode* root,int p,int q)
{
   //1.递归出口1:当前节点为空
   if(root == nullptr)  return nullptr;
   //2.递归出口2:当前节点就是p或q
   if(root->val == p || root->val == q)  return root;
   //3.递归搜索左右子树
   TreeNode* left = findLCA(root->left,p,q);
   TreeNode* right = findLCA(root->right,p,q);
   
   //两边都找到-->root是汇合点
   if(left != nullptr && right != nullptr) return root;
   //不是都找到，哪边有值传哪边，都没值自然传nullptr
   //不写三元表达式 写最朴素的
   if(left != nullptr)  return left;  //左有值 传left
   else if(right != nullptr)  return right; //右有值 传right
   else  return nullptr; //左右都空 传nullptr
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
    {
        vector<string> tok(n);
        for(int i = 0;i<tok.size();i++)
        {
            cin>>tok[i];
        }
        TreeNode* root = buildTree(tok);
        int p,q;
        cin>>p>>q;
        TreeNode* LCAnode = findLCA(root,p,q);
        int res = LCAnode->val;
        cout<<LCAnode->val<<'\n';
    }
    return 0;
}