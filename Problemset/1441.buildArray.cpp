#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int m = target.size();
        for (int i = 0,j = 1;i < m && j <= n;j++) {
            ans.push_back("Push");
            if (target[i] != j) 
                ans.push_back("Pop");
            else i++;
        }
        return ans;
    }
};
