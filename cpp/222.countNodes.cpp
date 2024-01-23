/*
issue:
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。 
*/

/*
solution:
当成普通二叉树进行求解 采用后序遍历计算Nodes
*/

#include<iostream>
using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {  //如果为nullptr 返回0 循环终止条件 也表示当前节点数量为0
            return 0;
        }
        int leftNums = countNodes(root->left);  //left 左子树的Nodes
        int rightNums = countNodes(root->right);//right 右子树的Nodes
        return leftNums+rightNums+1;    //左子树+右子树的Nodes加上根节点的数量1
    }
};