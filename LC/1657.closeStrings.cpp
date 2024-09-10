class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char,int> um1,um2;
        for (char ch:word1)um1[ch]++;
        for (char ch:word2)um2[ch]++;
        for (auto& [key,_]:um1) if (!um2.contains(key)) return false;
        vector<int> vi1,vi2;
        for (auto& [key,value]:um1) vi1.push_back(value);
        for (auto& [key,value]:um2) vi2.push_back(value);
        sort(vi1.begin(),vi1.end());
        sort(vi2.begin(),vi2.end());
        int n = vi1.size();
        for (int i  = 0;i < n;i++) {
            if (vi1[i] != vi2[i]) return false;
        }
        return true;
    }
};
