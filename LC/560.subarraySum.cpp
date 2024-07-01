
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int n = nums.size();
        vector<int> prefixSum(nums.size() + 1,0);
        for (int i = 0;i < nums.size();i++) {
            prefixSum[i + 1] = nums[i] + prefixSum[i];
        }
        for (int i = 0;i < n;i++) {
            int sum = 0;
            for (int j = i;j < n;j++) {
                if (prefixSum[j + 1] - prefixSum[i] == goal) ans++;
            }
        }
        return ans;
    }
};


/*
Method 1:prefixSum
前缀和嵌套两层for循环求sum == k的子数组 cnt++
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for (int i = 1;i <= n;i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {
                if (prefix[j+1] - prefix[i] == k) cnt++;
            }
        }
        return cnt;
    }
};
/*
Method 2:hash
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int cnt = 0;
        int preSum = 0;
        mp[0] = 1;
        for (int val:nums) {
            //preSum为左闭右闭当前元素的前缀和
            preSum += val;
            //如果找到了 说明有区间存在 和两数之和中遍历过程中找nums - target是一个道理
            if (mp.find(preSum - k) != mp.end()) {
                //加上出现的次数
                cnt += mp[preSum - k];
            }
            //不管是否找到 都插入mp中
            mp[preSum]++;
        }
        return cnt;
    }
};