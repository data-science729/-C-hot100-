#include<bits/stdc++.h>
using namespace std;

//二叉树最基本的模板 就这个结构体 别的不像链表有基本操作 二叉树都是具体题目具体分析
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

//遍历写上 很多题目要直接用到

// 前序遍历
void preorder(TreeNode* root)
{
    if (root == nullptr) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历
void inorder(TreeNode* root)
{
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// 后序遍历
void postorder(TreeNode* root)
{
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

//后续遍历迭代版(左->右->根)
void postorder_iter1(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* cur = root;
    TreeNode* prev = nullptr; //记录"上一个刚刚访问的节点" 来判断右子树有没有被访问
    while(cur != nullptr || !s.empty())
    {
        while(cur != nullptr)
        {
            s.push(cur); //根先压着
            cur = cur->left;
        }
        cur = s.top(); //左边到头了 先偷看栈顶顶点，不弹出
        //判断能不能访问cur：没有右孩子 或者右孩子刚刚被访问过
        if(cur->right == nullptr || cur->right == prev)
        {
            cout<<cur->val<<" "; // 左右都搞定了，终于可以访问（输出）当前节点
            s.pop(); //彻底处理完了，把它从栈里弹出
            prev = cur; //更新prev:刚才最后一个输出的就是cur
            cur = nullptr; //将cur置空 防止下一轮又顺着cur->left重复入栈
        }
        else
        {
            cur = cur->right; //继续将cur留在栈底，先转身去处理右子树
        }
    }
}

//层序遍历
void levelorder(TreeNode* root)
{
    if(root == nullptr) return; //空树直接返回
    queue<TreeNode*> q;
    q.push(root);  //根结点入队作为起点
    while(!q.empty())
    {
        int sz = q.size(); //记录下当前层的结点个数
        //一层一层处理
        for(int i =0;i<sz;i++)
        {
         TreeNode* cur = q.front();
         q.pop(); //队首出队(结点仍在树中)
         cout<<cur->val<<" ";
         if(cur->left != nullptr) q.push(cur->left);
         if(cur->right != nullptr) q.push(cur->right);
        }
        //处理完一层 换行
        cout<<endl;
    }
}

//释放内存(先释放孩子 再释放自己)
void destory(TreeNode* root)
{
    if(root == nullptr) return; //递归终点
    destory(root->left); //释放左子树
    destory(root->right); //释放右子树
    delete root; // 最后释放当前节点
}




