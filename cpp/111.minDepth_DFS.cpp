
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
题目问的是到叶子节点的最短距离，所以所有返回结果为 1 当然不是这个结果

另外这道题的关键是搞清楚递归结束条件

叶子节点的定义是左孩子和右孩子都为 null 时叫做叶子节点
当 root 节点左右孩子都为空时，返回 1
当 root 节点左右孩子有一个为空时，返回不为空的孩子节点的深度
当 root 节点左右孩子都不为空时，返回左右孩子较小深度的节点值
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        //1.左孩子和有孩子都为空的情况，说明到达了叶子节点，直接返回1即可
        if (root->left == nullptr and root->right == nullptr) return 1;
        //2.如果左孩子和由孩子其中一个为空，那么需要返回比较大的那个孩子的深度 
        //这里其中一个节点为空，说明m1和m2有一个必然为0，所以可以返回l+r+1
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (l == 0 or r == 0) return l+r+1;
        //3.最后一种情况，也就是左右孩子都不为空，返回最小深度+1即可
        return std::min(l,r)+1;
    }
};

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