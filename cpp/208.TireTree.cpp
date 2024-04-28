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

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() : children(26,nullptr),isEnd(false){}    //初始化rootnode
    
    void insert(string word) {
        Trie* temp = this;  //指向rootNode
        for (char ch:word) {
            if (temp->children[ch - 'a'] == nullptr) {
                temp->children[ch - 'a'] = new Trie();
            }
            temp = temp->children[ch - 'a'];    //无论之前TrieTree中是否存在字符 都要迭代temp
        }
        temp->isEnd = true; //遍历结束 把isEnd置1
    }
    
    bool search(string word) {
        Trie* temp = this;
        for (char ch:word) {
            if (temp->children[ch - 'a'] == nullptr) return false;  //说明没找到 false
            temp = temp->children[ch - 'a'];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* temp = this;
        for (char ch:prefix) {
            if (temp->children[ch - 'a'] == nullptr) return false;  //说明没找到 false
            temp = temp->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
