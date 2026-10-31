#include <bits/stdc++.h>
using namespace std;

// ==========================================
// 循环顺序队列（考研 408 标准实现：牺牲一个单元区分队空与队满）
// 核心思想：通过模运算 (%) 将一维数组在逻辑上构造成环形，彻底解决普通顺序队列的“假溢出”问题。
// 指针定义：
//   front: 指向当前队头元素
//   rear:  指向队尾元素的下一个空位置（即即将入队的位置）
// ==========================================
// 三种区分队空与队满的方法：
// 方法一：设置 flag 标志位
// 方法二：设置 len 记录有效元素个数
// 方法三：牺牲一个存储单元
const int MaxSize = 100;

struct SqQueue
{
    int data[MaxSize];
    int front; // 队头指针，指向队头元素
    int rear;  // 队尾指针，指向队尾元素的下一个空位置

    bool flag; //方法一:标志位判满
    int len; //方法二:当前有效元素个数
    SqQueue() : front(0), rear(0),flag(false),len(0) {}
};

// 1. 初始化
// 时间复杂度: O(1)
// 空间复杂度: O(1)
void InitQueue(SqQueue &Q)
{
    // 初始时队列为空，front 和 rear 均指向下标 0
    Q.front = 0;
    Q.rear = 0;
    Q.flag = false;
    Q.len = 0;
}

// 2. 判空
// 时间复杂度: O(1)
// 空间复杂度: O(1)

//方法1:flag标志位判空
bool QueueEmpty1(const SqQueue &Q)
{
    // 队头指针与队尾指针重合即为空
    return Q.front == Q.rear && Q.flag == false;
}

//方法2:直接维护队列程度len
bool QueueEmpty2(const SqQueue &Q)
{
    return Q.len == 0;
}

//方法3:牺牲单元
bool QueueEmpty3(const SqQueue &Q)
{
   return Q.front == Q.rear;
}

// 3. 判满（牺牲一个存储单元以区分队空与队满）
// 时间复杂度: O(1)
// 空间复杂度: O(1)

// 方法一：flag 标志位
bool QueueFull1(const SqQueue &Q)
{
    return Q.front == Q.rear && Q.flag == false;
}

// 方法二：len 计数器
bool QueueFull2(const SqQueue &Q)
{
    return Q.len == MaxSize;
}

// 方法三：牺牲一个存储单元
bool QueueFull3(const SqQueue &Q)
{
    return (Q.rear+1) % MaxSize == Q.front;
}

// 4. 求队列长度（当前有效元素个数）
// 时间复杂度: O(1)
// 空间复杂度: O(1)

// 方法一：flag 标志位
int QueueLength1(const SqQueue &Q)
{
    //front == rear时 还需要通过flag 判断是空还是满
    if(Q.front == Q.rear)
    {
        return Q.flag ? MaxSize:0;
    }
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

// 方法二：len 计数器
int QueueLength2(const SqQueue &Q)
{
    return Q.len ;
}

// 方法三：牺牲一个存储单元
int QueueLength3(const SqQueue &Q)
{
    return (Q.rear - Q.front + MaxSize) % MaxSize;
}

// 5. 入队：在队尾插入元素 x
// 时间复杂度: O(1)
// 空间复杂度: O(1)

// 方法一：flag 标志位
bool EnQueue1(SqQueue &Q, int x)
{
    if(QueueFull1(Q))
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;
    //标记最近一次操作为入队
    Q.flag = true;
    return true;
}

// 方法二：len 计数器
bool EnQueue2(SqQueue &Q, int x)
{
    if(QueueFull2(Q))
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;
    //有效元素个数加一
    Q.len++;
    return true;
}

// 方法三：牺牲一个存储单元
bool EnQueue3(SqQueue &Q, int x)
{
    if(QueueFull3(Q))
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1) % MaxSize;
    return true;
}

// 6. 出队：在队头删除元素，并用 x 返回
// 时间复杂度: O(1)
// 空间复杂度: O(1)

// 方法一：flag 标志位
bool DeQueue1(SqQueue &Q, int &x)
{
    if(QueueEmpty1(Q))  return false;
    //取出队头元素
     x = Q.data[Q.front] ;
    //将front向后移动一位
    Q.front = (Q.front+1)% MaxSize;
    //标记最后一次操作为出队
    Q.flag = false;
    return true;
}

// 方法二：len 计数器
bool DeQueue2(SqQueue &Q, int &x)
{
    if(QueueEmpty2(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
    Q.len--;
    return true;
}

// 方法三：牺牲一个存储单元
bool DeQueue3(SqQueue &Q, int &x)
{
    if(QueueEmpty3(Q))  return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
}

// 7. 获取队头元素：只读取不删除
// 时间复杂度: O(1)
// 空间复杂度: O(1)

// 方法一
bool GetHead1(const SqQueue &Q, int &x)
{
    if (QueueEmpty1(Q))
        return false;

    x = Q.data[Q.front];

    return true;
}

// 方法二
bool GetHead2(const SqQueue &Q, int &x)
{
    if (QueueEmpty2(Q))
        return false;

    x = Q.data[Q.front];

    return true;
}

// 方法三
bool GetHead3(const SqQueue &Q, int &x)
{
    if (QueueEmpty3(Q))
        return false;

    x = Q.data[Q.front];

    return true;
}


