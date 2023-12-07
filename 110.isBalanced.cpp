/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

*/

/*
solution:
求高度用后序遍历 左右中 根节点可以获取左右子树的信息
求深度用先序遍历 中左右 往下钻 
                            height      depth
              1             3           1
            /   \           
          2      3          2           2
         / \    /  \
        4   5   6   7       1           3

这道题判定左右子树高度相差不大于1
所以用后序遍历更为合适

后序遍历左右子树求高
如果左右子树高度相差大于1 return -1
如果不大于 说明是平衡二叉树 return 左右子树高度

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
    int Banlanced(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHigh = Banlanced(root->left);
        if (leftHigh == -1) return -1;
        int rightHigh = Banlanced(root->right);
        if (rightHigh == -1) return -1;
        if (std::abs(leftHigh-rightHigh) > 1) {
            return -1;
        }else {
            return std::max(leftHigh,rightHigh)+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        return Banlanced(root) == -1 ? false : true;
    }
};