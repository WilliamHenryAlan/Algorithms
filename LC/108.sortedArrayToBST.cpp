
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
BST的inorder就是有序数组
1.从中间进行分割 左子数组为左子树 右子数组为右子树构造
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
    TreeNode* buildTree(vector<int>& nums,int low,int high) {
        if (low > high) return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums,low,mid - 1);
        root->right = buildTree(nums,mid + 1,high);
        return root;
    }
};