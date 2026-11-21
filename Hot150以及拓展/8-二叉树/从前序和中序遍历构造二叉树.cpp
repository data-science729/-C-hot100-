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

//全局变量(多组数据时在main中resize/clear复用)
vector<int> preorder,inorder;
//哈希表:节点值->节点在中序序列中的下标
unordered_map<int,int> position;

//核心函数1:根据前序+中序构造二叉树
//preL:当前子树在前序里从哪个下标开始
//inL:当前子树在中序里从哪个下标开始
//len:当前子树一共有多少个节点，只要算出左子树长度leftlen
//右子树长度直接就是len-1-leftlen,下标位置顺着往后加
TreeNode* buildTree(int preL,int inL,int len)
{
    //1.递归出口:没有结点了 空子树返回空指针
    if(len <= 0)  return nullptr;
    //2.定根:前序区间的第1个元素是当前子树的根
    int rootVal = preorder[preL]; //取出根的值
    TreeNode* root = new TreeNode(rootVal);
    
    //3.找根:用哈希表O(1)查出根在中序里的下标
    int rootIdx = position[rootVal];

    //4.管长度:左子树节点个数 右子树节点个数
    int leftLen = rootIdx - inL;
    int rightLen = len - leftLen - 1;

    //5.递归建左右
    root->left = buildTree(preL +1,inL,leftLen);
    root->right = buildTree(preL+1+leftLen,rootIdx+1,rightLen);
    return root;
}

//核心函数2:层序遍历序列化并取出末尾连续null(树->字符串数组)
vector<string> serialize(TreeNode* root)
{
    vector<string> res;
    if(!root)  return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
       TreeNode* cur = q.front();
       q.pop();
       //判断出队的cur是否为真实节点
       if(cur != nullptr)
       {
        //是真实节点 用to_string将数字转为字符串计入答案
        res.push_back(to_string(cur->val));
        q.push(cur->left);
        q.push(cur->right);
       }
       else
       {
        //空指针 计入"null"
        res.push_back("null");
       }
     
    }
    //清理尾巴:叶子结点的左右nullptr也会进队 导致res末尾多出一堆连续的"null"
    //处理方法:只要数组不空 且最后一个元素是"null" 就一直删掉(pop_back)
    while(!res.empty() && res.back() == "null")
    {
        res.pop_back();
    }
    //返回整理好的序列化结果
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
   {
    preorder.resize(n);
    inorder.resize(n);
    position.clear();
    //1.输入前序遍历序列
    for(int i = 0 ;i<n;i++)
    {
        cin>>preorder[i];
    }
    //2.输入中序遍历序列，同时建立值->下标映射
    for(int i = 0;i<n;i++)
    {
        cin>>inorder[i];
        position[inorder[i]] = i;
    }
    //3.建树+序列化
    TreeNode* root = buildTree(0,0,n);
    vector<string> ans = serialize(root);
    //4.按格式输出
    cout<<ans.size()<<'\n';
    for(size_t i = 0;i<ans.size();i++)
    {
        if(i>0) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
   }
    return 0;
}