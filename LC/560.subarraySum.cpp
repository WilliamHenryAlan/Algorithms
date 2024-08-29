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
            prefix[i] = prefix[i-1] + nums[i-1];//构造前缀和
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
/*
review 2024.8.29
*/

1.构造前缀和数组需要明白prefixSum[i]的含义 
    prefixSum[i] = nums[i - 1] + nums[i - 2] + ... + nums[0]
2.prefixSum[0] = 0
3.由1得prefixSum[0]表示nums[0 - 1]是无意义的 只是为了可以统一计算

    nums = [4,2,5,2]
prefixSum= [0,4,6,11,13]
所以本题中`prefixSum[i]`就是```下标为0 - i的nums的数组和```
那么`prefixSum[i] - prefixSum[j]`就是```下标为j - i的nums的数组和```
也就是我们想找的子数组为k的答案

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum;
        int n = nums.size();
        prefixSum.resize(n + 1);
        prefixSum[0] = 0;
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            for (int j = 0;j <= i;j++) {
                if (prefixSum[i + 1] - k == prefixSum[j]) cnt++;
            }
        }
        return cnt;
    }
};