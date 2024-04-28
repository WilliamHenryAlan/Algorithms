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
构建二叉树必须需要inorder + preorder || postorder 
eg: inorder [9,3,1,5,20,7]
    postorder[9,1,5,7,20,3]
1.根据postorder确定rootnode
2.划分inorderArray
3.划分postorderArray
4.递归处理
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorderArr, vector<int>& postorderArr) {
        if (postorderArr.size() == 0) return nullptr;
        int rootVal = postorderArr.back();
        TreeNode* root = new TreeNode(rootVal);
        //leaf node
        if (postorderArr.size() == 1) return root;
        //search divide Index
        int divideIndex = 0;
        for (;divideIndex < inorderArr.size();divideIndex++) if (inorderArr[divideIndex] == rootVal) break;
        //divide inorderArray
        //[)左闭右开区间
        vector<int> leftInorderArr {inorderArr.begin(),inorderArr.begin() + divideIndex};
        vector<int> rightInorderArr {inorderArr.begin() + divideIndex + 1, inorderArr.end()};

        //divide postorderArray
        //[)左闭右开区间
        postorderArr.pop_back();
        vector<int> leftPostorderArr {postorderArr.begin(),postorderArr.begin() + leftInorderArr.size()};
        vector<int> rightPostorderArr {postorderArr.begin() + leftInorderArr.size(), postorderArr.end()};
        
        root->left = buildTree(leftInorderArr,leftPostorderArr);
        root->right = buildTree(rightInorderArr,rightPostorderArr);
        return root;
    }
};