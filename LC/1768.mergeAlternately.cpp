#include <iostream>
#include <string>
using namespace std;

/*
Method 1: 模拟
complexity:O(m + n)
*/
//直接使用c++ style string
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string ans;
        ans.resize(m + n);
        int i = 0,j = 0,k = 0;
        while (i < m && j < n) {
            ans[k++] = word1[i++];
            ans[k++] = word2[j++];
        }
        while (i < m) ans[k++] = word1[i++];
        while (j < n) ans[k++] = word2[j++];
        return ans;
    }
};
//string => c_str and c_str => string
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        char* ans = new char[m + n + 1];
        int i = 0,j = 0,k = 0;
        while (i < m && j < n) {
            ans[k++] = word1[i++];
            ans[k++] = word2[j++];
        }
        while (i < m) ans[k++] = word1[i++];
        while (j < n) ans[k++] = word2[j++];
        ans[k] = '\0';
        string str(ans);
        return str;
    }
};

