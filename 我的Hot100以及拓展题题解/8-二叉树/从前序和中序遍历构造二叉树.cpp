/*
 * ============================================================
 *  题目：前序中序构造二叉树
 * ============================================================
 *
 *  【题目描述】
 *    给定一棵二叉树的前序遍历序列和中序遍历序列，
 *    要求根据这两个遍历序列构造出原二叉树。
 *
 *    已知所有节点值互不相同，因此构造出的二叉树唯一。
 *
 *  【输入格式】
 *    第一行：一个整数 n，表示二叉树的节点数量。
 *
 *    第二行：n 个互不相同的整数，表示二叉树的前序遍历序列。
 *
 *    第三行：n 个互不相同的整数，表示二叉树的中序遍历序列。
 *
 *  【输出格式】
 *    将构造出的二叉树转换为层序遍历序列进行输出。
 *
 *    具体序列化规则：
 *      1. 序列首项为根节点。
 *      2. 随后按照层序遍历顺序，对每个非空节点依次输出
 *         左孩子和右孩子。
 *      3. 如果某个孩子为空，则输出 null。
 *      4. 删除序列末尾所有连续的 null。
 *
 *    第一行：输出序列化后的标记数量 k。
 *    第二行：输出 k 个标记，节点值或 null，以空格分隔。
 *
 *  【数据范围】
 *    1 ≤ n ≤ 3000
 *    -3000 ≤ val ≤ 3000
 *
 *    所有节点值互不相同。
 *
 *  【数据保证】
 *    前序遍历和中序遍历包含完全相同的节点值，
 *    且保证能够构成一棵合法的二叉树。
 *
 *  【输入样例】
 *    5
 *    3 9 20 15 7
 *    9 3 15 20 7
 *
 *  【输出样例】
 *    7
 *    3 9 20 null null 15 7
 *
 *  【核心考点】
 *    1. 根据前序遍历和中序遍历递归构造二叉树。
 *    2. 利用前序遍历确定根节点。
 *    3. 利用中序遍历划分左右子树。
 *    4. 使用队列实现二叉树的层序遍历。
 *    5. 按照指定规则进行二叉树序列化。
 *
 * ============================================================
 */

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



/*
 * ============================================================
 *  函数：buildTree
 *  功能：根据前序遍历和中序遍历构造二叉树
 *
 *  参数：
 *    preL：当前子树在前序序列中的起始下标
 *    inL ：当前子树在中序序列中的起始下标
 *    len ：当前子树的节点数量
 *
 *  返回值：
 *    当前构造出的二叉树的根节点指针
 */

//全局遍历序列
vector<int> preorder,inorder;
//哈希表:节点值->节点在中序序列中的下标
unordered_map<int,int> position;
TreeNode* buildTree(int preL,int inL,int len)
{
  
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
    {
        vector<int> preorder(n,0);
        vector<int> inorder(n,0);
        //输入前序遍历序列
        for(int i = 0;i<n;i++)
        {
            cin>>preorder[i];
        }
        //输入中序遍历序列同时建立哈希表
        unordered_map<int,int> position;
        for(int i = 0;i<n;i++)
        {
            cin>>preorder[i];
            position[preorder[i]] = i;
        }
        //调用buildTree()得到二叉树根节点
        //调用serialize()得到序列化结果
        //输出序列化结果的标记数量k
        //循环输出序列化结果
        

    }
    return 0;
}