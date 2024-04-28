/**
 * 2023.12.24
 * issue:判断是否为相同的树
 * solution：
 * 1.确认递归参数 两个树的root指针
 * 2.如果为nullptr return true
 * 3.如果两个指针有一个为nullptr 则return false
 * 4.经过上面两个判断之后 只剩下两个node都不为空的情况 这时候判断val是否一致
 * 5.当前子树判断结束 递归遍历各自的左子树和右子树
*/
#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q != nullptr) {
            return false;
        }else if (p != nullptr && q == nullptr) {
            return false;
        }else if (p == nullptr && q == nullptr) {
            return true;
        }else if (p->val != q->val) {
            return false;
        }else {
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
    }
};

/*
template
*/

#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==nullptr and q==nullptr) return true;
        else if (p==nullptr or q==nullptr) return false;
        else if (p->val != q->val) return false;
        else return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};