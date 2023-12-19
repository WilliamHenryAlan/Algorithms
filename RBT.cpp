/*
红黑树是BST
红黑树的性质：
1.红黑树的node要么是红要么是黑
2.红黑树的根节点是黑的
3.红黑树的叶子结点（叶子结点和平时的定义是不一样的 这里的叶子结点一般指外部结点 失败结点 NULL结点）是黑的
4.不能出现两个连续的红色结点
5.从任何一个节点出发到叶子结点 所含黑节点的数量必须是一致的

黑高bh：
从任何一个节点出发不包含该结点 到任意空结点的路径的 黑节点总数

*/
#include <iostream>
struct RBnode {
    int key;
    RBnode* parent;
    RBnode* left;
    RBnode* right;
    int color;
};