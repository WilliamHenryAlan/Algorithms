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
//1.确定递归函数的参数和返回值
//2.确认递归终止条件
//3.确认单层递归逻辑
/*
Method 1: recursion
*/
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

/*
Method 2: iteration
*/
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

//review 2024.2.5

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
            if (temp->right) {
                stk.push(temp->right);
            }
            if (temp->left) {
                stk.push(temp->left);
            }
        }
        return ret;
    }
};