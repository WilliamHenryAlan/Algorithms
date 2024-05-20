#include<iostream>
#include <vector>
#include <stack>
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

class Solution {
public:
    void postorder(TreeNode* root,std::vector<int>& ret) {
        if (root != nullptr) {
            postorder(root->left,ret);
            postorder(root->right,ret);
            ret.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        postorder(root,ret);
        return ret;
    }
};

class Solution {
public:
     vector<int> postorderTraversal(TreeNode* root) {
       std::stack<TreeNode*> st; //stack的类型为TreeNode的指针
        std::vector<int> ret;
        if (root == nullptr) {  //2.如果root为nullptr return
            return ret;
        }
        st.push(root);      //3.先压入root节点 preorder是中左右 所以要弹出root->val 

        while (!st.empty()) {
            TreeNode* temp = st.top();  //4.但是之后要处理root的左右孩子 如果直接弹出会失去link 所以要先保存root temp之后会一直被赋值为栈顶 深度搜索
            ret.push_back(st.top()->val);   //5.保存后推入root->val
            st.pop();                       //弹出
            //这之前和preorder一样 前序是先压入右子树 再压入左子树 后序遍历相反 由此可得中右左
            if (temp->left != nullptr) {    //6.左子树不为空 push
                st.push(temp->left);
            }
            if (temp->right != nullptr) {   //7.子树不为空 push
                st.push(temp->right);
            }
        }
        std::reverse(ret.begin(),ret.end());    //8.经过这步 中右左=>左右中 达到后序遍历
        return ret; 
    }
};

/*
review 2024.2.5
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        stack<TreeNode* > stk;
        if (!root) return ret;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* temp = stk.top();
            stk.pop();
            ret.emplace_back(temp->val);
            if (temp->left) stk.push(temp->left);
            if (temp->right) stk.push(temp->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};  