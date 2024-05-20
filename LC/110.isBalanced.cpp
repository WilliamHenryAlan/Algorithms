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
preorder:

1.如果遇到nullptr 则返回高度为0 是其中一种循环终止条件
2.因为求高度 是从左右子树收集信息给root 用postorder
3.单层递归逻辑：
            1.递归遍历左右子树高度 自己规定如果为不平衡二叉树 return-1
            2.左右node递归结束 处理root 算出左右子树差 如果 > 1则return -1
            3.如果上述情况都不满足 返回root的左右子树高的子树+1（1为root）
*/

class Solution {
public:
    int getHigh(TreeNode* root) {
        if (root == nullptr) return 0;  //1.确认循环种植条件
        //2.确认单层逻辑和遍历顺序
        int left = getHigh(root->left);
        if (left == -1) return -1;
        int right = getHigh(root->right);
        if (right == -1) return -1;
        int contrary = std::abs(left-right);
        if (contrary > 1) return -1;
        return std::max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if (getHigh(root) == -1) return false;
        return true;
    }
};

/*
solution:
求高度用后序遍历 左右中 根节点可以获取左右子树的信息
求深度用先序遍历 中左右 往下钻 
                            height      depth
              1             3           1
            /   \           
          2      3          2           2
         / \    /  \
        4   5   6   7       1           3

这道题判定左右子树高度相差不大于1
所以用后序遍历更为合适

后序遍历左右子树求高
如果左右子树高度相差大于1 return -1
如果不大于 说明是平衡二叉树 return 左右子树高度

*/
class Solution {
public:
    int Banlanced(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHigh = Banlanced(root->left);
        if (leftHigh == -1) return -1;
        int rightHigh = Banlanced(root->right);
        if (rightHigh == -1) return -1;
        if (std::abs(leftHigh-rightHigh) > 1) {
            return -1;
        }else {
            return std::max(leftHigh,rightHigh)+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        return Banlanced(root) == -1 ? false : true;
    }
};