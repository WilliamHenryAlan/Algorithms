/*
Trie树(alias:字典树,前缀树,单词查找树)的实现
普通的多叉树Node为value和指向孩子节点的指针数组
struct TreeNode {
    int value;  //数值
    TreeNode* children[nums];   //孩子节点的指针数组
};
*/
#include<iostream>
#include <string>
using namespace std;

struct TireNode {
    bool isEnd;     //tirenode不显式存储value 而是通过next的下标隐式存储
    TireNode* next[26];
    TireNode() : isEnd(false) {     //构造函数
        for (int i = 0;i < 26;i++) {
            next[i] = nullptr;
        }
    }
};
class Trie {
private:
    TireNode* root;     //root
public:
    Trie() {
        root = new TireNode(); 
    }
    void insert(string word) {
        TireNode* temp = root;
        for (char ch:word) {
            int index = ch - 'a';
            if (temp->next[index] == nullptr) {
                temp->next[index] = new TireNode();
            }
            temp = temp->next[index];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TireNode* temp = root;
        for (char ch:word) {
            int index = ch - 'a';
            if (temp->next[index] == nullptr) {
                return false;
            }
            temp = temp->next[index];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TireNode* temp = root;
        for (char ch:prefix) {
            int index = ch - 'a';
            if (temp->next[index] == nullptr) {
                return false;
            }
            temp = temp->next[index];
        }
        return true;     
    }
};
/*
2024.7.16
*/
struct TireNode {
    bool isEnd;
    TireNode* next[26];
    TireNode() : isEnd(false) {
        for (int i = 0;i < 26;i++) next[i] = nullptr;
    }
};
class Trie {
    TireNode* root;
public:
    Trie() : root(new TireNode()) {}
    
    void insert(string word) {
        TireNode* temp = root;
        for (char ch:word) {
            int index = ch - 'a';
            if (temp->next[index] == nullptr) {
                temp->next[index] = new TireNode();
            }
            temp = temp->next[index];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TireNode* temp = root;
        for (char ch:word) {
            int index = ch - 'a';
            if (temp->next[index] == nullptr) return false;
            temp = temp->next[index];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TireNode* temp = root;
        for (char ch:prefix) {
            int index = ch - 'a';
            if (temp->next[index] == nullptr) return false;
            temp = temp->next[index];
        }
        return true;
    }
};



// class Trie {
// private:
//     vector<Trie*> children;
//     bool isEnd;
// public:
//     Trie() : children(26,nullptr),isEnd(false){

//     }    //初始化rootnode
    
//     void insert(string word) {
//         Trie* temp = this;  //指向rootNode
//         for (char ch:word) {
//             if (temp->children[ch - 'a'] == nullptr) {
//                 temp->children[ch - 'a'] = new Trie();
//             }
//             temp = temp->children[ch - 'a'];    //无论之前TrieTree中是否存在字符 都要迭代temp
//         }
//         temp->isEnd = true; //遍历结束 把isEnd置1
//     }
    
//     bool search(string word) {
//         Trie* temp = this;
//         for (char ch:word) {
//             if (temp->children[ch - 'a'] == nullptr) return false;  //说明没找到 false
//             temp = temp->children[ch - 'a'];
//         }
//         return temp->isEnd;
//     }
    
//     bool startsWith(string prefix) {
//         Trie* temp = this;
//         for (char ch:prefix) {
//             if (temp->children[ch - 'a'] == nullptr) return false;  //说明没找到 false
//             temp = temp->children[ch - 'a'];
//         }
//         return true;
//     }
// };
