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
class Solution {
public:

 vector<int> inorderTraversal(TreeNode* root) {
      vector<int> vi;

      return vi;
    }
};

#include <iostream>
#include <stack>
using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            // 访问当前节点，并将右子节点入栈
            cout << current->val << " ";
            if (current->right != NULL) {
                s.push(current->right);
            }
            current = current->left;
        }

        // 若栈不为空，弹出栈顶节点作为当前节点
        if (!s.empty()) {
            current = s.top();
            s.pop();
        }
    }
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // 前序遍历输出结果
    cout << "Preorder traversal: ";
    preorderTraversal(root);

    return 0;
}


#include <iostream>
#include <stack>
using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            // 将当前节点及其左子节点入栈
            s.push(current);
            current = current->left;
        }

        // 左子树已经遍历完或者为空，弹出栈顶节点并访问
        current = s.top();
        s.pop();
        cout << current->val << " ";

        // 遍历右子树
        current = current->right;
    }
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // 中序遍历输出结果
    cout << "Inorder traversal: ";
    inorderTraversal(root);

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;
    TreeNode* lastVisited = NULL;

    while (current != NULL || !s.empty()) {
        if (current != NULL) {
            // 将当前节点及其左子节点依次入栈
            s.push(current);
            current = current->left;
        } else {
            TreeNode* peekNode = s.top();
            // 如果当前节点的右子节点为空或者已经访问过，则访问当前节点
            if (peekNode->right == NULL || peekNode->right == lastVisited) {
                cout << peekNode->val << " ";
                lastVisited = peekNode;
                s.pop();
            } else {
                // 否则，将右子节点作为当前节点继续遍历
                current = peekNode->right;
            }
        }
    }
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // 后序遍历输出结果
    cout << "Postorder traversal: ";
    postorderTraversal(root);

    return 0;
}
