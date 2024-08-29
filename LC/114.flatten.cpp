/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left == nullptr) {
                root = root->right;
            }else {
                TreeNode* lr = root->left;
                while (lr->right != nullptr) {
                    lr = lr->right;
                }
                lr->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};
