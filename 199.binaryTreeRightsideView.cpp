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
        std::vector<int> rightSideView(TreeNode* root) {
            std::queue<TreeNode*> q;
            std::vector<int> ret;
            if (root == nullptr) {
                return ret;
            }
            q.push(root);
            while (!q.empty()) {    //第一个while循环把要处理的Node压入队列
                int size = q.size();
                while (size) {
                    TreeNode* temp = q.front();   //因为循环中大量call q.front() 可以保存队头元素减少开销
                    q.pop();    //迭代 pop 所以要提前记录size
                    if (size == 1) {
                        ret.push_back(temp->val);   //保存一层的value
                    }
                    if (temp->right != nullptr) {
                        q.push(temp->right);
                    }
                    if (temp->left != nullptr) {
                        q.push(temp->left);
                    }
                }
            }
            return ret;
        }
    };