/*
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
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
/*
solution:
高度和深度的概念
1.题目要求求最大深度 转化为求根节点高度 这样可以用后序遍历回溯 从而求解
2.确定了用后序遍历 写出递归三部曲

*/
/*
Method 2:DFS
*/
class Solution {
public:
    //这个写法的思路实际上是用后序遍历求高度
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);    
        int right = maxDepth(root->right);  //分别求出左右子树的高度
        return std::max(left,right)+1;
        //return left >= right ? left+1:right+1;  //对比左右子树高度 返回根节点高度
    }
};
//求深度 并进行回溯
class Solution{
public:
    void traverse(TreeNode* root,int& depth,int& res) {
        if (root == nullptr) {
            return ;
        }
        depth++;
        if (root->left == nullptr and root->right == nullptr) {
            res = std::max(res,depth);
        }
        /*
        左右孩子在同一层 depth是一致的
        */
        traverse(root->left,depth,res);
        traverse(root->right,depth,res);
        depth--;
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int res = 0;
        traverse(root,depth,res);
        return res;
    }
};

/*
Method 2:iteration
1.用level order
*/
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