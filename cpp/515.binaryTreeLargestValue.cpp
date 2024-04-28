/*
给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
示例1：

输入: root = [1,3,2,5,3,null,9]
输出: [1,3,9]

示例2：

输入: root = [1,2,3]
输出: [1,3]

*/
#include<iostream>
#include <vector>
#include <queue>
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
    int maximumValue(std::vector<int>& vi) {
        int ret = vi[0];
        for (int& i:vi) {
            if (i > ret) {
                ret = i;
            }
        }
        return ret;
    }
    std::vector<int> largestValues(TreeNode* root) {
        std::vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> vi;
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                vi.push_back(temp->val);
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
            }
            ret.push_back(maximumValue(vi));    //传入一层的数据vector 找最大值 并压入返回的数组中
        }
        return ret;
    }
};