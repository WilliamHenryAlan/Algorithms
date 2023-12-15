/*
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
*/

/*
solution:

*/
#include<iostream>
#include <vector>
#include <queue>
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            depth++;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
        }
        return depth;
    }
};