/*
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。
*/

/*
solution:
记录每层最左边的Node值 ret = q.front()->val
遍历结束 返回ret
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
BFS

*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> q;
        int ret;
        q.push(root);
        while (!q.empty()) {    //与levelOrder的写法大体一致
            int size = q.size();
            ret = q.front()->val;   //此时的q.front()->val就是最左侧的node
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
        return ret;
    }
};
/*
DFS
tips:
1.题目给出左侧的node不代表一定要是leftChild
2.
*/
//reduced version:
class Solution {
public:
    int max_depth;
    int ret;
    void dfs(TreeNode* root,int depth) {
        if (root == nullptr) return;
        if (root->left == nullptr and root->right == nullptr) { 
            if (depth > max_depth) {    //遇到leftNode查看此时深度 如果大于最大深度 则更新最大深度 并记录当前最左侧的value
                max_depth = depth;
                ret = root->val;
            }
        }
        /*
        depth++;
        dfs(root->left,depth);
        dfs(root->right,depth);
        depth--;
        隐藏了回溯过程和下面的代码等效
        */
        dfs(root->left,depth+1); 
        dfs(root->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,1);
        return ret;
    }
};
/*
review 2024.1.29
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return -1;
        std::queue<TreeNode*> q;
        q.push(root);
        int ret = -1;
        while (!q.empty()) {
            int size = q.size();
            ret = q.front()->val;
            while (size--) {
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return ret;
    }
}; 