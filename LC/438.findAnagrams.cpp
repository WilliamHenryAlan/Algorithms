
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size(),m = s.size();
        vector<int> ans;
        unordered_map<char,int> um,target;
        for (char c:p) target[c]++;//把p映射为hashtable
        for (int i = 0;i < m;i++) {
            um[s[i]]++;//每次更新滑动窗口的数据
            if (i < n - 1) continue;//先滑动到定长窗口 也就是p.size()
            int j = i - n + 1;
            if (um == target) ans.push_back(j);//满足条件 则收集结果
            um[s[j]]--;//退出窗口
            if (um[s[j]] == 0) um.erase(s[j]);//c++需要erase
        }
        return ans;
    }
};
