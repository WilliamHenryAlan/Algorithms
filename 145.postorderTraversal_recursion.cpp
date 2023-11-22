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
    void postorder(TreeNode* root,std::vector<int>& ret) {
        if (root != nullptr) {
            postorder(root->left,ret);
            postorder(root->right,ret);
            ret.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        postorder(root,ret);
        return ret;
    }
};
int main() {

}