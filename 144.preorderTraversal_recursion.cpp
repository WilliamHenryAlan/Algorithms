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
    void preorder(TreeNode*& root,std::vector<int>& vi)
    {
        if (root != nullptr)
        {
            vi.push_back(root->val);
            preorder(root->left,vi);
            preorder(root->right,vi);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> vi;
        preorder(root,vi);
        return vi;
    }
};