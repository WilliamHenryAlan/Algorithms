/*
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]

示例 2：

输入：root = [1]
输出：[[1]]

示例 3：

输入：root = []
输出：[]


*/
#include<iostream>
#include <vector>
#include <queue>
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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> vi;
            while (size--) {
                TreeNode* temp = q.front();
                vi.push_back(temp->val);
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                q.pop();
            }
            ret.push_back(vi);
        }
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};