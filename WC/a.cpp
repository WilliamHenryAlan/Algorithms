
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//修改
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer(matrix);
        int r,c;
        for (c = 0;c < answer[0].size();c++) {
            int temp = -1;
            for (r = 0;r < answer.size();r++) {
                temp = max(answer[r][c],temp);
            }
            for (int k = 0;k < answer.size();k++) {
                if (answer[k][c] == -1) {
                    answer[k][c] = temp;
                }
            }
        }
        return answer;
    }
};

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer(matrix);
        int r,c;
        for (c = 0;c < answer[0].size();c++) {
            int temp = -1;
            for (r = 0;r < answer.size();r++) {
                temp = max(answer[r][c],temp);
            }
            for (int k = 0;k < answer.size();k++) {
                if (answer[k][c] == -1) {
                    answer[k][c] = temp;
                }
            }
        }
        return answer;
    }
};

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> myset;
        int len = s.size();
        if (len <= 1) return false;
        for (int i = 0;i < len - 1;i++) {
            myset.insert(s.substr(i,2));
        }
        reverse(s.begin(),s.end());
        for (int i = 0;i < len - 1;i++) {
            if (myset.find(s.substr(i,2)) != myset.end()) return true;
        }
        return false;
    }
};

class Solution {
public:
    long long countSubstrings(string s, char c) {
        int len = s.size();
        int cnt = 0;
        for (int i = 0;i < len;i++) {
            if (s[i] != c) continue;
            for (int j = i;j < len;j++) {
                if (s[j] == s[i]) cnt++;
            }
        }      
        return cnt;
    }
};



