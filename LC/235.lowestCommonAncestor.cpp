#include<iostream>
#include <vector>

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
/*
review 2024.3.9

公共祖先可以是自己
*/
//iteration
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        根据二叉搜索树的性质 left->val < root->val < right->val
        if (root->val - left->val) * (root->val - root->val) > 0 说明在同一侧
        */
        while ((long(root->val - p->val) * long(root->val - q->val)) > 0) {
            root = root->val < p->val?root->right:root->left;
        }
        return root;
    }
};
//recursion
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val and q->val < root->val) 
        return lowestCommonAncestor(root->left,p,q);
        if (p->val > root->val and q->val > root->val)
        return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};