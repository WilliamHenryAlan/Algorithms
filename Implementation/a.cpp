#include <iostream>
using namespace std;

struct TireNode {
    bool isEnd;
    TireNode* next[26];
};
class Trie {
public:
    Trie() :isEnd(false),next({0}){
        
    }
    
    void insert(string word) {

    }
    
    bool search(string word) {

    }
    
    bool startsWith(string prefix) {
		return true;
    }
};
int main() {
	
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
