class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        unordered_set<int> set;
        for (int& val:arr) um[val]++;
        for (auto& pair:um) {
            if (set.contains(pair.second)) return false;
            set.insert(pair.second);
        }
        return true;
    }
};
