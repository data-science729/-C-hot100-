#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;   //数据域
    TreeNode* left;  //左孩子指针
    TreeNode* right; //右孩子指针
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right): val(x), left(left), right(right) {}
};

