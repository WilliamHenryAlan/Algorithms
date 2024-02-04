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
class Solution {
public:
    int ans = INT_MAX;
    TreeNode* prev = nullptr;
    void traversal(TreeNode* root) {
        if (!root) return ;
        traversal(root->left);
        if (prev) {
            ans = min(root->val - prev->val,ans);
        }
        prev = root;
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return ans;
    }
};