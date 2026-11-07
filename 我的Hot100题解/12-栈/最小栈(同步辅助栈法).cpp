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
 * -2^31 <= x <= 2^31 - 1  -->应当用long long
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

//st:正常存储所有元素
//minst:辅助栈 存储当前每个位置对应的最小值




struct MinStack
{
    stack<long long> st; //主栈
    stack<long long> minst; //辅助栈

    //1.入栈
    void push(long long x)
    {
        st.push(x);
        if(minst.empty())  minst.push(x);
        else  minst.push(min(x, minst.top()));
    }

    //2.出栈
    void pop()
    {
        st.pop();
        minst.pop();
    }
    
    //3.获取栈顶元素
    long long top()
    {
        return st.top();
    }

    //4.获取最小元素
    long long getMin()
    {
        return minst.top();
    }
};

int main()
{
    long long q;
    cin >> q;
    MinStack s;
    while(q--)
    {
        string op;
        cin >> op;
        if(op == "push")
        {
            long long x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop")
        {
            s.pop();
        }
        else if(op == "top")
        {
            cout << s.top() << '\n';
        }
        else if(op == "getMin")
        {
            cout << s.getMin() << '\n';
        }
    }
    return 0;
}

