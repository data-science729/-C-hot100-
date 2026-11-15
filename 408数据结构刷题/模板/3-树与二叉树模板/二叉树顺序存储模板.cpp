/*
 * ============================================================
 *  二叉树的顺序存储结构：前提与性质
 * ============================================================
 *
 * 【一、前提】
 *   顺序存储没有存指针，父子关系完全靠"下标的数学关系"隐含表示，
 *   因此必须满足：
 *   1. 按完全二叉树的编号存放：自上而下、每层从左到右依次编号，
 *      结点放入数组中对应下标的位置。
 *   2. 下标从 1 开始（0 号位不用）。
 *   3. 一般二叉树要先"补全"成完全二叉树，缺失的位置用空标记占位。
 *   4. 空标记必须能和有效结点值区分开（如假设结点值不会是 -1）。
 *
 * 【二、下标关系】（下标从 1 开始，共 n 个结点，结点编号为 i）
 *   +----------+-------------+-------------------------------+
 *   |   关系   |    公式     |             条件              |
 *   +----------+-------------+-------------------------------+
 *   | 左孩子   | 2i          | 2i <= n，否则无左孩子         |
 *   | 右孩子   | 2i + 1      | 2i + 1 <= n，否则无右孩子     |
 *   | 双亲     | floor(i/2)  | i > 1（i = 1 为根，无双亲）   |
 *   +----------+-------------+-------------------------------+
 *   下标从 0 开始时：左孩子 2i+1，右孩子 2i+2，双亲 floor((i-1)/2)。
 *
 * 【三、常用结论】（完全二叉树，n 个结点）
 *   1. 叶子判断：i > floor(n/2) 的结点都是叶子，
 *      分支结点编号为 1 ~ floor(n/2)。
 *   2. 第 k 层的编号范围：2^(k-1) ~ 2^k - 1。
 *   3. 同一层的结点下标连续，层序遍历 = 顺着数组扫一遍。
 *   4. 树高：h = floor(log2(n)) + 1，等价于 ceil(log2(n+1))。
 *   5. 度为 1 的结点至多 1 个，若存在，必为编号 floor(n/2) 的结点
 *      （n 为偶数时，它只有左孩子）。
 *
 * 【四、适用场景与局限】
 *   适合：完全二叉树、满二叉树（典型应用：堆 / 优先队列），
 *         空间利用率 100%，找孩子、双亲均为 O(1)。
 *   不适合：形态不规则的二叉树，需补大量空位；
 *         最坏情况为右斜树，n 个结点需要长度 2^n - 1 的数组，
 *         空间浪费随 n 指数级增长。
 *         此外，插入、删除结点时子树下标需整体变动，操作不方便。
 *
 * 【五、小结】
 *   前提：按完全二叉树编号存放，空缺补空标记，下标从 1 开始
 *   核心：左孩子 2i，右孩子 2i+1，双亲 floor(i/2)
 *   优点：无需指针，层序遍历直接扫数组
 *   缺点：一般二叉树浪费空间，增删不便
 * ============================================================
 */

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;  //数组最大容量
const int EMPTY = -1;  //空结点标记


struct SeqTree
{
    int data[MAXN+1] ; //下标从1开始 0号位不用
    int size; //数组使用到的最大下标
    //构造函数 将数组全部填充成空标记
    SeqTree():size(0){
        for(int i = 0;i<MAXN;i++)  data[i] = EMPTY;
    }
};

//--------常用函数-------------

//1.判断下标i处是否有结点
bool exist(const SeqTree& t,int i)
{
    return i>=1 && i<=t.size && t.data[i] != EMPTY;
}

//2.双亲结点 左孩子 右孩子编号
int parentof(int i)  {return i/2;}
int leftChild(int i) {return 2*i;}
int rightChild(int i) {return 2*i+1;}

//3.遍历
void preOrder(const SeqTree& t,int i)
{
    //先根 后面依次循环调用
    if(!exist(t,i)) return;
    cout<<t.data[i]<<" ";
    preOrder(t,leftChild(i));
    preOrder(t,rightChild(i));
}

// 中序遍历
void inOrder(const SeqTree& t, int i) {
    if (!exist(t, i)) return;
    inOrder(t, leftChild(i));
    cout << t.data[i] << " ";
    inOrder(t, rightChild(i));
}

// 后序遍历
void postOrder(const SeqTree& t, int i) {
    if (!exist(t, i)) return;
    postOrder(t, leftChild(i));
    postOrder(t, rightChild(i));
    cout << t.data[i] << " ";
}

//层序遍历
void levelOrder(const SeqTree& t)
{
    for(int i = 1;i<t.size;i++)
    {
        if(exist(t,i)) cout<<t.data[i]<<" ";
    }
}

