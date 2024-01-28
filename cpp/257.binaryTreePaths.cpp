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
Method: 前序遍历 递归
1.如果是nullptr return
2.每次都把暂存在temp
3.如果path中没有路径 就直接添加val 
                   如果有路径 就添加 “->” 再添加val
4.如果此时是leafNode 则把path暂存
5.递归遍历左右子树
6.回溯
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
practice 2024.1.28
*/
class Solution {
public:
    void backtracking(TreeNode* root,std::vector<std::string>& ans,std::string& path) {
        if (root == nullptr) return;
        std::string temp = path;
        path += (path == ""?"":"->") + std::to_string(root->val);
        if (root->left == nullptr and root->right == nullptr) ans.emplace_back(path);
        backtracking(root->left,ans,path);
        backtracking(root->right,ans,path);
        path = temp;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ret;
        std::string path = "";
        backtracking(root,ret,path);
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
        str += std::to_string(root->val);   //root
        if (root->left == nullptr and root->right == nullptr) {
            ret.push_back(str);
        }else {
            str += "->";
            constructPaths(root->left,ret,str); //left
            constructPaths(root->right,ret,str);//right
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> ret;
        constructPaths(root,ret,"");
        return ret;
    }
};