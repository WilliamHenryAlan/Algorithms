/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。 

示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false

*/

/*
solution:
1.判断二叉树是否对称 就是判断左子树翻转是不是可以得到右子树
2.用到递归函数 想到递归三部曲：
            判断函数参数 返回值
            循环终止条件
            每层循环的操作

*/

#include<iostream>
#include <vector>
#include <queue>
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
    bool recursion(TreeNode* left,TreeNode* right) {
        if (left == nullptr and right != nullptr) {
            return false;
        }else if (left != nullptr and right == nullptr) {
            return false;
        }else if (left == nullptr and right == nullptr) {
            return true;
        }else if (left->val != right->val) {
            return false;
        }else return recursion(left->left,right->right) and recursion(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) return true;
        return recursion(root->left,root->right);
    }
};