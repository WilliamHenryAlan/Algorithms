
/*
使用递归：
1.preorder and postorder 都可以实现反转 
2.inorder不行 会使处理过的node再次处理

tips：
1.c++11之前 NULL和0可以互相转化 会产生问题
2.c++11之后尽量使用nullptr nullptr表示指针常量

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        std::swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};