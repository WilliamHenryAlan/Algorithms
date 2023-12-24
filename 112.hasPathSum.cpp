/**
 * 2023.12.23
 * 
 * solution:
 * 1.
*/
struct TreeNode {
    int val;
    TreeNode* left,*right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};
class Solution {
public:
    bool backTracking(TreeNode* root,int targetSum) {
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == 0;
        }

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
    }
};