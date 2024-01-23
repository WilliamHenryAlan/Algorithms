/*
issue:
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

 
*/


/*
solution:
运用了完全二叉树的特性 当二叉树很大时 可以不遍历中间区域的Nodes
1.向左右两侧求深度并记录
2.如果左右两侧深度一致 说明这个子树是满二叉树 可以用2^depth-1 快速求出节点数量
3.如果不一致 用后序遍历求出节点数量
*/
#include<iostream>
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {  //如果为nullptr 返回0 循环终止条件 也表示当前节点数量为0
            return 0;
        }
        int leftDepth = 0,rightDepth = 0;
        TreeNode* left = root->left,*right = root->right;
        while (left) {    //计算左侧的深度
            leftDepth++;
            left = left->left;
        }
        while (right) {   //计算右侧的深度
            rightDepth++;
            right = right->right;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) -1;     //移位运算优先级低 要加括号
        }
        //子树不为完全二叉树
        int leftNums = countNodes(root->left);  //left 左子树的Nodes
        int rightNums = countNodes(root->right);//right 右子树的Nodes
        return leftNums+rightNums+1;    //左子树+右子树的Nodes加上根节点的数量1
    }
};