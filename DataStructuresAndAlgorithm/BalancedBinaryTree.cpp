/*
平衡二叉搜索树AVL树
*/
#include <iostream>
#include <vector>
struct AVLNode {
    int key;
    int balance;    //平衡因子等于左子树高度-右子树高度 = 0 1 或者 -1
    AVLNode* left ,* right;
    AVLNode(): key(0),left(nullptr),right(nullptr) {}
    AVLNode(int x) : key(x),left(nullptr),right(nullptr) {}
};
AVLNode* insertAVLNode(int x);

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

    AVLNode* root = nullptr;

    std::cout << "inorder: ";
    inorder(root);
    std::cout << std::endl;
}

/*
插入node分4种情况：
                1.LL
                2.RR
                3.LR
                4.RL
*/
AVLNode* insertAVLNode(int x) {

}