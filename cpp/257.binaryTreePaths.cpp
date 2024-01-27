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

*/
class Solution {
public:
    void dfs(TreeNode* root,std::vector<std::string>& ans,std::string &path) {
        if (root == nullptr) return;
        std::string temp = path;
        path += (path == "" ? "" : "->") + std::to_string(root->val);
        if (root->left == nullptr and root->right == nullptr) ans.push_back(path);
        dfs(root->left,ans,path);
        dfs(root->right,ans,path);
        path = temp;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ret;
        std::string path = "";
        dfs(root,ret,path);
        return ret;
    }
};

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