/**
 * =============================================================================
 * 经典数据结构设计题：底层手写小顶堆 (Min-Heap Design)
 * =============================================================================
 * 
 * 【题目背景与目标】
 * 堆（Heap）是计算机科学中最高效、最基础的动态极值维护结构，也是自然语言处理
 * （NLP）中 Beam Search（束搜索）和图论 Dijkstra 最短路算法的底层核心。
 * 本题要求：禁止使用 C++ STL 的 priority_queue、make_heap 等现成函数，
 * 亲手使用 vector 从零设计并实现一个标准的「小顶堆」（MyMinHeap）。
 * 
 * 【题目描述】
 * 请设计一个类 MyMinHeap，支持以下 5 种核心操作：
 *   1. void push(int val) : 向堆中插入一个整数 val，耗时 O(log N)
 *   2. void pop()          : 弹出堆顶元素（最小值），耗时 O(log N)
 *   3. int top()           : 获取堆顶元素（最小值），耗时 O(1)
 *   4. int size()          : 获取当前堆中元素总个数，耗时 O(1)
 *   5. bool empty()        : 判断堆是否为空，耗时 O(1)
 * 
 * 【底层原理与索引核心备忘】
 * 堆逻辑上是一棵“完全二叉树”，物理上使用一维动态数组 vector 连续存储。
 * 对于下标为 i 的任意节点（从 0 开始计数）：
 *   - 父节点下标    : parent = (i - 1) / 2
 *   - 左孩子节点下标 : left   = 2 * i + 1
 *   - 右孩子节点下标 : right  = 2 * i + 2
 * 
 * 【两大核心动力引擎】
 *   - 上浮 (sift_up)   : 插入新元素到数组尾部后，若其小于父节点，逐层向上与父节点交换。
 *   - 下沉 (sift_down) : 弹出堆顶时，将数组末尾元素搬移至堆顶，若其大于子节点，
 *                       逐层向下与较小的儿子交换。
 * 
 * -----------------------------------------------------------------------------
 * 【ACM 模式输入格式】
 * 第一行包含一个正整数 M (1 <= M <= 10^5)，表示接下来操作的总指令数。
 * 接下来 M 行，每行包含一条操作指令，格式为下列之一：
 *   - "push x" : 插入整数 x (-10^9 <= x <= 10^9)
 *   - "pop"    : 弹出当前堆顶最小值（若堆为空则忽略此次操作）
 *   - "top"    : 打印当前堆顶最小值（若堆为空输出 -1）
 *   - "size"   : 打印当前堆内元素数量
 * 
 * 【ACM 模式输出格式】
 * 对于每个 "top" 和 "size" 指令，输出一行对应的整型结果。
 * 
 * 【输入样例】
 * 8
 * push 5
 * push 3
 * push 8
 * top
 * pop
 * top
 * size
 * pop
 * 
 * 【输出样例】
 * 3
 * 5
 * 1
 * =============================================================================
 */

#include <bits/stdc++.h>
using namespace std;
//Heap在逻辑上是一颗完全二叉树 每一层都是满的 最后一层即使不满 所有节点也必须严格从左到右紧密排列
//minheap(小顶堆) 要求任意一个节点 都小于等于它的左右子节点
//-->整棵树的根节点(堆顶) 一定是"全局最小值"
//和BST区别 它只管父子之间谁大谁小 完全不管左右兄弟之间谁大谁小
//底层 用vector<int>数组 就能完美存储 公式 对下标为i(根节点i=0)的任意节点 parent =(i-1)/2,left_child=2*i+1,right_child=2*i+2
//有了这个公式 我们完全不需要指针 只要通过简单的乘除法 就能让数组自由穿梭于父子节点之间
class MyMinHeap {
private:
    vector<int> heap; // 底层数组

    // 引擎 1：上浮操作 (插入时调用) push
    void sift_up(int i) {
        //只要不是根节点，并且当前节点比它的父节点还要小 就往上浮
        while(i>0)
        {
            int parent = (i-1)/2;
            if(heap[i]<heap[parent])
            {
               swap(heap[i],heap[parent]);
               i = parent ; 
            }
            else
            {
                break ; //堆序满足 停止上浮
            }
        }
        
    }

    // 引擎 2：下沉操作 (弹出堆顶时调用) pop
    void sift_down(int i) {
        int n = heap.size();
        //只要当前节点还有做孩子 就尝试下沉
        while(2*i+1<n)
        {
         int left = 2*i + 1;
         int right = 2*i + 2;
         int smallest = i ; // 记录父左右三人中最小值的下标
         if(left<n && heap[left]<heap[smallest])
         {
            smallest = left;
         }
         if(right<n && heap[right]<heap[smallest])
         {
            smallest = right;
         }
         if(smallest == i)
         {
            break ; //如果当前节点就是最小的 说明满足堆序 停止下沉
         }
         //否则 跟较小的那个儿子交换 并继续向下探查
         swap(heap[i],heap[smallest]);
         i = smallest;
        }
        
    }

public:
    MyMinHeap() {}  //构造函数

    void push(int val) {
     heap.push_back(val); //放到末尾
     sift_up(heap.size()-1); //上浮到合适位置
        
    }

    void pop() {
       if(heap.empty()) return ;
       heap[0] = heap.back() ; //末尾移到堆顶
       heap.pop_back() ; //删除末尾
       sift_down(0) ; //栈顶元素下沉归位
    }

    int top() {
        return heap[0] ; 
        return -1;
    }

    int size() {
        return heap.size();
        return 0;
    }

    bool empty() {
        return heap.empty();
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    while (cin >> M)
    {
        MyMinHeap min_heap;
        while (M--)
        {
            string op;
            cin >> op;
            if (op == "push")
            {
                int x;
                cin >> x;
                min_heap.push(x);
            }
            else if (op == "pop")
            {
                min_heap.pop();
            }
            else if (op == "top")
            {
                if (min_heap.empty()) cout << -1 << "\n";
                else cout << min_heap.top() << "\n";
            }
            else if (op == "size")
            {
                cout << min_heap.size() << "\n";
            }
        }
    }
    return 0;
}
