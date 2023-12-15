/*
prompt:
this指针是常量指针 不可改
*/
#include <iostream>
#include <vector>
struct TNode {
    int val;
    TNode* left ,* right;
    TNode(): val(0),left(nullptr),right(nullptr) {}
    TNode(int x) : val(x),left(nullptr),right(nullptr) {}
};
TNode* insertTNode(int x);
void createTree(TNode*& root,const std::vector<int>& data);
void createTree_recursion();
void inorder(TNode* root);
void deleteTNode(int x);

int main() {
    std::vector<int> vi;   
    vi.push_back(50); 
    vi.push_back(66); 
    vi.push_back(60); 
    vi.push_back(26); 
    vi.push_back(21); 
    vi.push_back(30); 
    vi.push_back(70); 
    vi.push_back(68); 

    TNode* root = nullptr;
    createTree(root,vi);
    std::cout << "inorder: ";
    inorder(root);
    std::cout << std::endl;
}

TNode* insertTNode(int x) {
    TNode* ret = new TNode(x);
    return ret;
}
//插入节点 迭代实现
void createTree(TNode*& root,const std::vector<int>& data) {
    if (root != nullptr) {
        return ;
    }
    root = new TNode(data[0]);
    int len = data.size();
    for (int i = 1;i < len;i++) {   //1.遍历整个vector
        TNode* temp = root;         //每次从root节点出发 开始寻找
        while (true) {              //2.插入节点
            if (data[i] == temp->val) {
                break;
            }else if (data[i] > temp->val) {
                if (temp->right == nullptr) {
                    temp->right = insertTNode(data[i]);
                }else  temp = temp->right;
            }else {
                if (temp->left == nullptr) {
                    temp->left = insertTNode(data[i]);
                }else temp = temp->left;
            }
        }
    }
}
//递归实现
void createTree_recursion() {

}
void inorder(TNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}
void deleteTNode(int x) {
    
}