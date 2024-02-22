/*
用字典树
*/
#include <iostream>
#include <vector>
using namespace std;

class Trie {
public:
    Trie() {
        isEnd = false;
        memset(children, 0, sizeof(children)); //按字节初始化为0
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';      //这个才是Trie树中真正意义上的存储
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true; //是node->isEnd = true 不是isEnd = true 前者是当点的 后者是root的
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';      
            if (node->children[ch] == nullptr) return false;
            node = node->children[ch];
        }  
        return true;
    }
    bool isSinglePath() {
        int count = 0;
        for (int i = 0;i < 26;i++) {
            if (children[i] != nullptr) count++;
            if (count > 1) return false;
        }
        return true;
    }
    char getCharacter() {
        for (int i = 0;i < 26;i++) {
            if (children[i]) return 'a' + i;
        }
        return '\0';
    }
public:
    Trie* children[26]; //因为只存储26个小写英文字母 比vector更快
    bool isEnd;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root = new Trie();
        for (string& s:strs) {
            root->insert(s);
        }
        string prefix = "";
        Trie* node = root;
        while (node && !node->isEnd && node->isSinglePath()) {
            char ch = node->getCharacter();
            prefix += ch;
            node = node->children[ch - 'a'];
        }
        return prefix;
    }
};

