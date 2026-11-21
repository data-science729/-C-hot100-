/*
 * ============================================================================
 * 题目名称：二叉树中序遍历
 * 题目来源：力扣 Hot100 / 考研机试真题
 * ============================================================================
 *
 * 【题目描述】
 * 给定一棵二叉树，输出它的中序遍历序列。
 * 中序遍历按照“左子树 -> 根节点 -> 右子树”的顺序访问节点。
 *
 * 二叉树使用层序序列表示：
 *   1. 序列首项表示根节点；
 *   2. 随后对已读到的每个非空节点依次读取左、右孩子，null 表示对应孩子为空；
 *   3. 序列末尾不影响树结构的连续 null 省略，空树的序列长度为 0。
 *
 * 【输入格式】
 * - 第一行：输入一个整数 k，表示层序序列的标记数量。
 * - 第二行：当 k > 0 时，输入 k 个用空格分隔的标记。每个标记是一个整数或 null，
 *           第一个标记一定是整数。输入保证这些标记能按题目描述构成一棵二叉树。
 *
 * 【输出格式】
 * - 第一行：输出一个整数 n，表示树中节点数量。
 * - 第二行：当 n > 0 时，输出 n 个整数，表示中序遍历结果，整数之间用单个空格分隔；
 *           当 n = 0 时不再输出其他行。
 *
 * 【数据范围】
 * - 0 <= n <= 100
 * - -100 <= val <= 100
 * - 0 <= k <= 2n + 1
 *
 * 【输入样例】
 * 4
 * 1 null 2 3
 *
 * 【输出样例】
 * 3
 * 1 3 2
 *
 * ============================================================================
 */
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

//1.递归算法
//root:当前需要遍历的子树根结点
//ans:保存遍历结果的数组:使用引用传递避免每次递归复制数组
void inorder(TreeNode* root,vector<int>& ans)
{
    //1.递归终止条件
    if(root == nullptr) return;
    //2.遍历左子树
    inorder(root->left,ans);
    //3.访问根结点
    ans.push_back(root->val);
    //4.遍历右子树
    inorder(root->right,ans);
}

//2.迭代算法
vector<int> inorder2(TreeNode* root)
{
    vector<int> ans;  //保存最终中序遍历序列
    stack<TreeNode*> s; //辅助栈，存"先路过但还没访问"的根节点
    TreeNode* cur = root; //游标指针
    //当前指针非空 或者栈里有还没处理的节点 就继续
    while(cur != nullptr ||!s.empty())
    {
        while(cur!=nullptr)
        {
           s.push(cur);
           cur = cur->left;
        }
        //左边到头 弹栈并访问
        cur = s.top();   // 左边走到头了，取出栈顶元素（最左下角的节点）
        s.pop();  //把它从栈中弹出来
        ans.push_back(cur->val); //访问这个节点，把它的值放进结果数组
        //转向右子树
        cur = cur->right;
    }
    return ans;
}

//层序建树:把字符串数组tok还原为一颗二叉树 返回根节点指针
TreeNode* buildTree(const vector<string>& tok)
{
    int k = tok.size();  //获取层序序列中一共有多少个标记(数字或null)
    if(k == 0) return nullptr; //如果标记数量为0 说明是空树 返回空指针
    TreeNode* root = new TreeNode(stoi(tok[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1; //下标i指向tok中下一个还没被读取的标记(0已经被root占用所以从1开始)
    //只要还有没读完的标记(i<k)，且队列里还有等待分配孩子的节点 就继续建树
    while(i<k && !q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        //1.读取左孩子
        if(i<k)
        {
            if(tok[i] !="null")
            {
                node->left = new TreeNode(stoi(tok[i]));
                q.push(node->left);
            }
            i++;  // 不管刚才读到的是数字还是 "null"，这个标记都消费掉了，下标 i 往后移一格
        }
        //2.读取右孩子
        if(i<k)
        {
            if(tok[i] != "null")
            {
                node->right = new TreeNode(stoi(tok[i]));
                q.push(node->right);
            }
            i++;
        }
    }
    return root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; //层序序列标记数量
    while(cin>>k)
    {
        vector<string> tok(k);
        for(int i = 0;i<k;++i)
        {
          cin>>tok[i];
        }
        TreeNode* root = buildTree(tok);
        vector<int> ans = inorder2(root);
        int n = ans.size();
        cout<<n<<'\n';  //第一行输出节点数量并换行
        if(n>0)
        {
            for(int i = 0;i<n;++i)
            {
                if(i>0)  cout<<' '; // 控制空格：第0个数前面不加空格，从第1个数开始先输出一个空格，避免行末多余空格
                cout<<ans[i];
            }
            cout<<'\n'; //这一行所有数字输出完毕后 输出一个换行符
        }
    }
    return 0;
}