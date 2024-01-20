#include<iostream>
#include <vector>
#include <stack>
using namespace std;

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
    vector<int> preorderTraversal(TreeNode* root) {     //1.根据递归的实现 模拟栈的过程
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
            if (temp->right != nullptr) {   //6.因为栈是FILO 入栈顺序为右左 这样出栈才能是左右 右子树不为空 push
                st.push(temp->right);
            }
            if (temp->left != nullptr) {    //7.左子树不为空 push
                st.push(temp->left);
            }
        }
        return ret; //栈空 遍历结束
    }
};