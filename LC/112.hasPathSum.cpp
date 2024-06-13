#include <iostream>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr and root->right == nullptr and targetSum == root->val) {
            return true;
        }
        bool l = hasPathSum(root->left,targetSum-root->val);
        bool r = hasPathSum(root->right,targetSum-root->val);
        return l or r;
    }
};