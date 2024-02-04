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
因为BST的inorder为增序序列
*/
class Solution {
public:
    TreeNode* prev = nullptr;
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool l = isValidBST(root->left);
        if (!prev or prev->val < root->val) {
            prev = root;
        }else return false;
        bool r = isValidBST(root->right);
        return l and r;
    }
};
