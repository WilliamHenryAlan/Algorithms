/*
组合数学

    因为题目没要求具体的数组下标 只要求各数

1.遍历数组 记录每个元素出现次数

2.遍历hash 用组合公式求解ans个数


*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cache[101] = {0},n = nums.size(),ans = 0;
        for (int i = 0;i < n;i++) cache[nums[i]]++;
        for (int i = 0;i < 101;i++) 
            if (cache[i] > 0) ans += cache[i] * (cache[i] - 1) / 2;
        return ans;
    }
}; 