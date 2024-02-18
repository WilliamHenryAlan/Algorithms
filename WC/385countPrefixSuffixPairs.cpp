#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret = 0;
        for (int i = 0;i < words.size();i++) {
            for (int j = i + 1;j < words.size();j++) {
                if (check(words[i],words[j])) ret++;
            }
        }   
        return ret;
    }
    bool check(string& s1,string& s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        for (int i = 0,j = 0;i < n && j < m;j++,i++) {
            if (s1[i] != s2[j]) return false;
        }
        for (int i = n-1,j = m-1;i >= 0 && j >= 0;j--,i--) {
            if (s1[i] != s2[j]) return false;
        }
        return true;
    }
};
