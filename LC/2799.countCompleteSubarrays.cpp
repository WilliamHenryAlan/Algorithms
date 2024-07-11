class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = unordered_set<int> (nums.begin(),nums.end()).size();//去重
        unordered_map<int,int> hash;//记录滑动窗口中的出现次数
        int l = 0,r = 0,ans = 0;
        for (;r < nums.size();r++) {
            hash[nums[r]]++;
            while (n == hash.size()) {//当满足都有数字出现一次时
                int x = nums[l++];
                if (--hash[x] == 0) hash.erase(x);
            }
            //跳出loop后 找到满足条件的最短数组 所以左侧的每加一个元素 都是一个answer
            ans += l;
        }
        return ans;
    }
};
