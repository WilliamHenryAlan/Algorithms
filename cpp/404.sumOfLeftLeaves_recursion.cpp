
/*
给定二叉树的根节点 root ，返回所有左叶子之和。

*/

/*
solution：


prompt:
用深搜的方法 使用 后序遍历更容易理解
左叶子的定义要清晰 这道题不能直接处理递归模版中的当前节点 因为不知道是左孩子还是右孩子
所以只能在当前节点的上一层进行判定
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {  
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {  //作为leaf node来说 是没有叶子结点的
            return 0;                                           //是否加此条件不影响正确性 但是会减少递归层数
        }
        int leftSum = sumOfLeftLeaves(root->left);
        if ((root->left != nullptr) && root->left->left == nullptr && root->left->right == nullptr) {
            leftSum = root->left->val;
        }
        int rightSum = sumOfLeftLeaves(root->right);
        return leftSum+rightSum;
    }
};


//version A:
// class Solution {
// public:
//     void sum(TreeNode* root,int& ret) {     //无需创建新的函数 ret可以作为返回值递归传递
//         if (root == nullptr) {
//             return;
//         }                                   //少递归结束条件 虽然结果是对的 但是增加了递归层数
//         if (root->left != nullptr && (root->left->left == nullptr && root->left->right == nullptr)) {
//             ret += root->left->val;
//         }
//         sum(root->left,ret);
//         sum(root->right,ret);
//     }
//     int sumOfLeftLeaves(TreeNode* root) {
//         int ret = 0;
//         sum(root,ret);
//         return ret;
//     }
// };