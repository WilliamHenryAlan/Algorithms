class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> us1(nums1.begin(),nums1.end()),us2(nums2.begin(),nums2.end());
        for (const int& val:us1) if (!us2.contains(val)) ans[0].push_back(val);
        for (const int& val:us2) if (!us1.contains(val)) ans[1].push_back(val);
        return ans;
    }
};
