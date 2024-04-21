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
/*
solution:
运用了完全二叉树的特性 当二叉树很大时 可以不遍历中间区域的Nodes
1.向左右两侧求深度并记录
2.如果左右两侧深度一致 说明这个子树是满二叉树 可以用2^depth-1 快速求出节点数量
3.如果不一致 用后序遍历求出节点数量
*/

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
/*
review 2024.2.22
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int l_depth = 0,r_depth = 0;
        TreeNode* l = root,* r = root;
        while (l->left) {
            l = l->left;
            l_depth++;
        }
        while (r->right) {
            r = r->right;
            r_depth++;
        }
        if (l_depth == r_depth) {
            return (2 << l_depth) - 1; //完全二叉树总会触发一次 因为左右子树必然有一颗是满二叉树 可以用2^n - 1计算
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


/*
solution:
当成普通二叉树进行求解 采用后序遍历计算Nodes
*/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {  //如果为nullptr 返回0 循环终止条件 也表示当前节点数量为0
            return 0;
        }
        int leftNums = countNodes(root->left);  //left 左子树的Nodes
        int rightNums = countNodes(root->right);//right 右子树的Nodes
        return leftNums+rightNums+1;    //左子树+右子树的Nodes加上根节点的数量1
    }
};
//精简版
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};