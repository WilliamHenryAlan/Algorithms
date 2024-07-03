class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> hash;
        int ans = 0,prefixSum = 0;
        hash[0] = 1;
        for (int& val:nums) {
            prefixSum += val;
            if (hash.find(prefixSum - goal) != hash.end()) 
                ans += hash[prefixSum - goal];
            hash[prefixSum]++;
        }
        return ans;
    }
};
