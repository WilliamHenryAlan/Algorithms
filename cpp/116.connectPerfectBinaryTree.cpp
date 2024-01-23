#include <iostream>
#include <queue>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* record = nullptr;
            while (size--) {
                Node* temp = q.front();
                q.pop();
                temp->next = record;
                record = temp;
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
            }
        }
        return root;
    }
};