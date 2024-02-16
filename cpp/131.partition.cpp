#include<iostream>
#include <vector>
#include <string>
using namespace std;
/*
subset子集问题
读清题意
s = "aab"
return vector<vector<string>> = [["a","a","b"],["aa","b"]]
*/


class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return {};
        dfs(s,0);
        return ans;
    }
    void dfs(string& s,int start) {
        if (start >= s.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = start;i < s.size();i++) {
            if (isPalindrome(s,start,i)) {
                string str = s.substr(start,i - start + 1);
                path.push_back(str);
            }else continue;
            dfs(s,i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(string& str,int l,int r) {
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }
};

int main() {
    string str = "aab";
    Solution A;
    A.partition(str);
}
