/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
*/

/*
solution:
看清题目给最小深度的概念 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
明确遍历顺序：采用后序遍历 左右中
和求最大深度一样 如果只修改max部分 当出现   1
                                    /   \
                                nullptr  2
                                        / \
                                        3 5
这样的情况时 最小深度应该是3 但返回却是1 因为左子树为空 return 0+1
所以应该加上判定  左子树为空 右子树不为空时 return 右子树高度+1
                右子树为空 左子树不为空时 return 左子树高度+1

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr and root->right != nullptr) {         //左子树为空 右子树不为空时 return 右子树高度+1
            return minDepth(root->right)+1;
        }else if (root->left != nullptr and root->right == nullptr) {   //右子树为空 左子树不为空时 return 左子树高度+1
            return minDepth(root->left)+1;
        }else return std::min(minDepth(root->left),minDepth(root->right))+1;    //左右子树都不为空 return min+1
    }
};