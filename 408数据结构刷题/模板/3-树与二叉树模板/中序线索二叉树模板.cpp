#include <bits/stdc++.h>
using namespace std;

enum PointerTag { Link, Thread };

struct BiThrNode {
    int data;
    BiThrNode *lchild, *rchild;
    PointerTag ltag, rtag;

    // 构造函数：默认把标志位初始化为 Link，彻底避开未初始化的坑
    BiThrNode(int val)
        : data(val), lchild(nullptr), rchild(nullptr), ltag(Link), rtag(Link) {}
};

typedef BiThrNode* BiThrTree;

BiThrTree pre = nullptr;

void InThreading(BiThrTree p) {
    if (p == nullptr) return;

    InThreading(p->lchild);

    if (p->lchild == nullptr) {
        p->ltag = Thread;
        p->lchild = pre;
    }

    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rtag = Thread;
        pre->rchild = p;
    }

    pre = p;

    InThreading(p->rchild);
}

void InOrderThreading(BiThrTree T) {
    pre = nullptr;
    InThreading(T);
    if (pre != nullptr && pre->rchild == nullptr) {
        pre->rtag = Thread;
        pre->rchild = nullptr;
    }
}

BiThrTree FirstNode(BiThrTree p) {
    if (p == nullptr) return nullptr;
    while (p->ltag == Link) {
        p = p->lchild;
    }
    return p;
}

BiThrTree NextNode(BiThrTree p) {
    if (p == nullptr) return nullptr;
    if (p->rtag == Thread) {
        return p->rchild;
    }
    return FirstNode(p->rchild);
}

void InOrderTraverse_Thr(BiThrTree T) {
    for (BiThrTree p = FirstNode(T); p != nullptr; p = NextNode(p)) {
        cout << p->data << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 构造示例树：
    //        1
    //      /   \
    //     2     3
    //      \   /
    //       4 5
    BiThrTree root = new BiThrNode(1);
    root->lchild = new BiThrNode(2);
    root->rchild = new BiThrNode(3);
    root->lchild->rchild = new BiThrNode(4);
    root->rchild->lchild = new BiThrNode(5);

    InOrderThreading(root);
    InOrderTraverse_Thr(root); // 输出: 2 4 1 5 3

    return 0;
}
