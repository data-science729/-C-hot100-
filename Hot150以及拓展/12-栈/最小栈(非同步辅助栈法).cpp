/**
 * 题目：最小栈
 * 来源：力扣 Hot 100 / 考研机试真题
 *
 * 【题目描述】
 * 实现一个栈，除普通的压栈、弹栈和读取栈顶操作外，还能在任意时刻读取栈内最小元素。
 * 开始时栈为空，支持以下操作：
 *   - push x : 将整数 x 压入栈顶；
 *   - pop    : 删除栈顶元素；
 *   - top    : 输出栈顶元素；
 *   - getMin : 输出栈内最小元素。
 *
 * 【输入格式】
 * 第一行输入整数 q，表示操作数。
 * 接下来 q 行，每行输入一条操作，格式为 push x、pop、top 或 getMin。操作按输入顺序执行。
 * 输入保证执行 pop、top 或 getMin 时栈非空。
 *
 * 【输出格式】
 * 对每条 top 或 getMin 操作输出一行对应结果。push 和 pop 操作不输出内容。
 *
 * 【数据范围】
 * 1 <= q <= 3 * 10^4
 * -2^31 <= x <= 2^31 - 1
 *
 * 【输入样例】
 * 7
 * push -2
 * push 0
 * push -3
 * getMin
 * pop
 * top
 * getMin
 *
 * 【输出样例】
 * -3
 * 0
 * -2
 */
#include<bits/stdc++.h>
using namespace std;

struct MinStack
{
    stack<long long> st;
    stack<long long> minst;

    void push(long long x)
    {
        st.push(x);
        //关键:minst为空或者新元素<=当前最小值才压入minst
        if(minst.empty() || x<=minst.top())
        {
            minst.push(x);
        }
    }

    void pop()
    {
        //如果弹出的元素正好等于当前最小值 minst也同步弹出
        if(st.top() == minst.top())
        {
            st.pop();
            minst.pop();
        }
        st.pop();
    }

    long long top()
    {
        return st.top();
    }

    long long getMin()
    {
        return minst.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    while (cin >> q) {
        MinStack ms;
        string op;
        for (int i = 0; i < q; i++) {
            cin >> op;
            if (op == "push") {
                long long x;
                cin >> x;
                ms.push(x);
            } else if (op == "pop") {
                ms.pop();
            } else if (op == "top") {
                cout << ms.top() << '\n';
            } else if (op == "getMin") {
                cout << ms.getMin() << '\n';
            }
        }
    }
    return 0;
}