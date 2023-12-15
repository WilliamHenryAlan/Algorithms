/*
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。
*/

/*
solution:
使用preorder
确认递归参数 
终止条件
单个循环
处理每个node把值压入string

如果是leaf node 把string加入std::vector<std::string> ret
如果是 branch node 则添加->字符串 并且向左右进行递归
*/

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
    void constructPaths(TreeNode* root,std::vector<std::string>& ret,std::string str) {
        if (root == nullptr) {
            return ;
        }
        str += std::to_string(root->val);
        if (root->left == nullptr and root->right == nullptr) {
            ret.push_back(str);
        }else {
            str += "->";
            constructPaths(root->left,ret,str);
            constructPaths(root->right,ret,str);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ret;
        constructPaths(root,ret,"");
        return ret;
    }
};