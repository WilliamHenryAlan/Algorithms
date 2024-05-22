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
Method 1:recursion
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val > val) root->left = insertIntoBST(root->left,val);
        else root->right =  insertIntoBST(root->right,val);
        return root;
    }
};

/*
Method 2: iteration
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > val) {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            }else {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            }
        }
        return root;
    }
};