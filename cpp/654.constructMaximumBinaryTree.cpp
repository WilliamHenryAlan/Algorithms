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
1.找到maximum
2.建立val = maximum的node
3.如果是leftNode return root
4.分隔左右数组
5.递归遍历

可以进行优化 不创建vector 而是用下标
*/
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        vector<int>::iterator iter = max_element(nums.begin(),nums.end());
        TreeNode* root = new TreeNode(*iter);
        if (nums.size() == 1) return root;
        vector<int> left {nums.begin(),iter};
        vector<int> right {iter + 1, nums.end()};
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};