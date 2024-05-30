#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n + 1,0);
        vector<int> temp(n,0);
        vector<int> ans(queries.size(),0);
        unordered_set<char> hash = {'a','e','i','o','u'};   //可以设置一个ckeck func
        for (int i = 0;i < n;i++) { //预处理 把string首尾为voewl的string映射为1
            if (hash.find(words[i].front()) != hash.end() && hash.find(words[i].back()) != hash.end()) {    //find可以换成count
                temp[i] = 1;
            }
        }
        for (int i = 1;i <= n;i++) { //构建前缀和数组
            prefixSum[i] = prefixSum[i - 1] + temp[i - 1];
        }
        for (int i = 0;i < queries.size();i++) {
            ans[i] = prefixSum[queries[i][1] + 1] - prefixSum[queries[i][0]];
        }
        return ans;
    }
};