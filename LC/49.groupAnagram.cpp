/*
根据判断异位词排序后是否相同来分组

例如：aab,aba,baa排序后都是aab
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for (string& str:strs) {
            string s = str;
            sort(s.begin(),s.end());
            um[s].push_back(str);
        }
        vector<vector<string>> ans;
        for (const pair<string,vector<string>>& p:um) ans.push_back(p.second);
        return ans;
    }
};
