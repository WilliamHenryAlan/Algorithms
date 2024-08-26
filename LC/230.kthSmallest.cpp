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
BST inorder 为增序序列
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        function<void(TreeNode*)> dfs = [&](TreeNode* root){
            if (root == nullptr) return;
            dfs(root->left);
            if (--k == 0) ans = root->val;
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
};
