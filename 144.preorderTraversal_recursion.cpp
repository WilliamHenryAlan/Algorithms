<<<<<<< HEAD
#include<iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
//1.确定递归函数的参数和返回值
//2.确认递归终止条件
//3.确认单层递归逻辑
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
    void preorder(TreeNode*& root,std::vector<int>& vi)
    {
        if (root != nullptr)
        {
            vi.push_back(root->val);
            preorder(root->left,vi);
            preorder(root->right,vi);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> vi;
        preorder(root,vi);
        return vi;
    }
};
=======
#include<iostream>
#include <vector>
using namespace std;
//Definition for a binary tree node.
//1.确定递归函数的参数和返回值
//2.确认递归终止条件
//3.确认单层递归逻辑
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
    void preorder(TreeNode*& root,std::vector<int>& vi)
    {
        if (root != nullptr)
        {
            vi.push_back(root->val);
            preorder(root->left,vi);
            preorder(root->right,vi);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> vi;
        preorder(root,vi);
        return vi;
    }
};
>>>>>>> 6c5e81194f4125fdad51ca233ccd425cc5cf7020
