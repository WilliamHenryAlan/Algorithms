#include<iostream>
#include <stack>
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
Method 1: iteration
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (!st.empty() ||  cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;        //找到左子树下左下角的node
            } else {
                cur = st.top(); //指向中node
                st.pop();
                result.push_back(cur->val);//处理root
                cur = cur->right;   //右遍历
            }
        }
        return result;
    }
};
/*
Method 2: recursion
*/
class Solution {
public:
void inorder(TreeNode* root,vector<int>& vi)
{
    if (root != nullptr)
    {
        inorder(root->left,vi);
        vi.push_back(root->val);
        inorder(root->right,vi);
    }
}
 vector<int> inorderTraversal(TreeNode* root) {
            vector<int> vi;
            inorder(root,vi);
            return vi;
    }
};
