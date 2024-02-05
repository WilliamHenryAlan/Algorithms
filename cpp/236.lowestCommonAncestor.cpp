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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return root; //如果为nullptr return nullptr
        if (root == q or root == p) return root;    //覆盖了四种情况
        TreeNode* l = lowestCommonAncestor(root->left,p,q); //收集leftChild
        TreeNode* r = lowestCommonAncestor(root->right,p,q);//收集rightChild
        if (!l and !r) return nullptr;  //都没找到p,q return nullptr
        if (l and !r) return l; //只找到了p或者q 其中一个人 return
        if (!l and r) return r;
        return root;    //p,q在异侧
    }
};