/*

solution:
前中后序遍历的特点 为什么要用后序遍历
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
/*
四种情况
左子树  右子树
0       1       左或者右空 表示不对称 return false
1       0
0       0       如果左右都为空 说明对称 返回true
判断左右都不为空 再判断val是否一致 不一致
再继续判断内外侧节点

*/
class Solution {
public:
    bool compare(TreeNode* leftTree,TreeNode* rightTree) {
        if (leftTree == nullptr and rightTree != nullptr) return false;
        else if (leftTree != nullptr and rightTree == nullptr) return false;
        else if (leftTree == nullptr and rightTree == nullptr) return true;
        else if (leftTree->val != rightTree->val) return false;
        else return compare(leftTree->left,rightTree->right) and compare(leftTree->right,rightTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left,root->right);
    }
};

/*
review 2024.2.3
*/
class Solution {
public:
    bool traversal(TreeNode* l,TreeNode* r) {
        if (!l and !r) return true;
        if (!l and r) return false;
        if (l and !r) return false;
        if (l->val != r->val) return false;
        return traversal(l->left,r->right) and traversal(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return traversal(root->left,root->right);
    }
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
/*
review 2024.6.17
*/
class Solution {
public:
    bool dfs(TreeNode* l,TreeNode* r) {
        if (l == nullptr && r == nullptr) {
            return true;
        }else if (l == nullptr && r != nullptr) {
            return false;
        }else if (l != nullptr && r == nullptr) {
            return false;
        }else if (l->val != r->val) {
            return false;
        }else return dfs(l->left,r->right) && dfs(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return dfs(root->left,root->right);
    }
};