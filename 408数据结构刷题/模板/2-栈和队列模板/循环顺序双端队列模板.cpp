
#include <bits/stdc++.h>
using namespace std;

// ==========================================
// 循环顺序双端队列（Deque）
//
// 核心思想：
// 双端队列允许在队头和队尾两端进行插入、删除操作。
// 使用循环数组存储元素，通过取模运算实现数组首尾相连。
//
// 指针约定：
// front：指向队头元素所在的位置。
// rear：指向队尾元素的下一个空位置。
// len：记录当前队列中的有效元素个数。
//
// 例如：
// data:  [10] [20] [30] [  ] [  ]
//         ↑           ↑
//       front        rear
//
// 此时：
// 队头元素：data[front] = 10
// 队尾元素：data[(rear-1+MaxSize)%MaxSize] = 30
//
// 判空：len == 0
// 判满：len == MaxSize
// 最大容量：MaxSize
// ==========================================

struct Deque
{
    static constexpr int MaxSize = 100;

    int data[MaxSize];  // 存储双端队列中的元素
    int front;          // 指向队头元素
    int rear;           // 指向队尾元素的下一个空位置
    int len;            // 当前元素个数

    // 初始化：
    // front = rear = 0，表示队列从数组下标0开始
    // len = 0，表示当前队列为空
    Deque() : front(0), rear(0), len(0) {}
};

// ==========================================
// 1. 判空
// ==========================================
// 当 len == 0 时，说明队列中没有任何有效元素。
// 注意：这里不使用 front == rear 判断空，
// 因为循环队列中 front == rear 也可能表示队满。
// 本模板通过 len 消除这种歧义。
bool DequeEmpty(const Deque &D)
{
    return D.len == 0;
}

// ==========================================
// 2. 判满
// ==========================================
// 当 len == MaxSize 时，说明数组中的存储空间已经全部使用。
// 本模板不需要像牺牲一个存储单元法那样预留一个空位置。
bool DequeFull(const Deque &D)
{
    return D.len == Deque::MaxSize;
}

// ==========================================
// 3. 获取当前元素个数
// ==========================================
// 由于使用 len 记录元素数量，因此直接返回即可。
// 时间复杂度：O(1)
int DequeLength(const Deque &D)
{
    return D.len;
}

// ==========================================
// 4. 队头插入
// ==========================================
// 操作：将元素 x 插入到当前队头的前面。
//
// 例如：
// 插入前：10 20 30
// 插入后：5  10 20 30
//
// 注意：
// front 原本指向旧队头。
// 因此需要先将 front 向前移动一个位置，
// 再将新元素 x 放入 front 所指向的位置。
//
// front - 1 可能变成负数，
// 所以使用 (front - 1 + MaxSize) % MaxSize
// 保证下标始终处于 [0, MaxSize-1]。
//
// 时间复杂度：O(1)
bool PushFront(Deque &D, int x)
{
    // 队列已满，无法继续插入
    if (DequeFull(D))
        return false;

    // 先将队头指针向前移动一格
    D.front = (D.front - 1 + Deque::MaxSize) % Deque::MaxSize;

    // 将新元素放入新的队头位置
    D.data[D.front] = x;

    // 有效元素个数加一
    D.len++;

    return true;
}

// ==========================================
// 5. 队尾插入
// ==========================================
// 操作：将元素 x 插入到当前队尾的后面。
//
// 例如：
// 插入前：10 20 30
// 插入后：10 20 30 40
//
// 注意：
// rear 指向队尾元素的下一个空位置，
// 因此可以直接将新元素放入 data[rear]。
// 插入完成后，rear 再向后移动一格。
//
// rear + 1 可能超过数组下标范围，
// 因此使用 (rear + 1) % MaxSize 实现循环移动。
//
// 时间复杂度：O(1)
bool PushBack(Deque &D, int x)
{
    // 队列已满，无法继续插入
    if (DequeFull(D))
        return false;

    // 将新元素放入 rear 当前指向的空位置
    D.data[D.rear] = x;

    // rear 后移一格，继续指向新的队尾后方空位置
    D.rear = (D.rear + 1) % Deque::MaxSize;

    // 有效元素个数加一
    D.len++;

    return true;
}

// ==========================================
// 6. 队头删除
// ==========================================
// 操作：删除当前队头元素，并通过引用参数 x 返回被删除的值。
//
// 例如：
// 删除前：10 20 30
// 删除后：20 30
// x = 10
//
// 注意：
// front 指向当前队头元素，
// 因此先取出 data[front]，再将 front 向后移动一格。
//
// 时间复杂度：O(1)
bool PopFront(Deque &D, int &x)
{
    // 队列为空，无法删除
    if (DequeEmpty(D))
        return false;

    // 取出当前队头元素
    x = D.data[D.front];

    // front 后移一格，指向新的队头元素
    D.front = (D.front + 1) % Deque::MaxSize;

    // 有效元素个数减一
    D.len--;

    return true;
}

// ==========================================
// 7. 队尾删除
// ==========================================
// 操作：删除当前队尾元素，并通过引用参数 x 返回被删除的值。
//
// 例如：
// 删除前：10 20 30
// 删除后：10 20
// x = 30
//
// 注意：
// rear 指向队尾元素的下一个空位置，
// 所以不能直接删除 data[rear]。
// 必须先将 rear 向前移动一格，
// 使其指向真正的队尾元素，然后再取出该元素。
//
// rear - 1 可能变成负数，
// 因此使用 (rear - 1 + MaxSize) % MaxSize。
//
// 时间复杂度：O(1)
bool PopBack(Deque &D, int &x)
{
    // 队列为空，无法删除
    if (DequeEmpty(D))
        return false;

    // rear 前移一格，定位当前真正的队尾元素
    D.rear = (D.rear - 1 + Deque::MaxSize) % Deque::MaxSize;

    // 取出队尾元素
    x = D.data[D.rear];

    // 有效元素个数减一
    D.len--;

    return true;
}

// ==========================================
// 8. 获取队头元素（不删除）
// ==========================================
// 只读取队头元素，不改变 front、rear 和 len。
// 时间复杂度：O(1)
bool GetFront(const Deque &D, int &x)
{
    // 队列为空，没有队头元素
    if (DequeEmpty(D))
        return false;

    // front 直接指向队头元素
    x = D.data[D.front];

    return true;
}

// ==========================================
// 9. 获取队尾元素（不删除）
// ==========================================
// 只读取队尾元素，不改变 front、rear 和 len。
// 时间复杂度：O(1)
//
// 注意：rear 指向队尾后面的空位置，
// 因此队尾元素下标为 (rear - 1 + MaxSize) % MaxSize。
bool GetBack(const Deque &D, int &x)
{
    // 队列为空，没有队尾元素
    if (DequeEmpty(D))
        return false;

    // 通过 rear 向前移动一格，定位真正的队尾元素
    int pos = (D.rear - 1 + Deque::MaxSize) % Deque::MaxSize;

    x = D.data[pos];

    return true;
}
