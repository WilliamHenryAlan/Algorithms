/*
greedy
*/
class Solution {
public:
    int maxScore(vector<int>& nums) {
        //1.重排数组 如果negative放在前面 后面的前缀和也会收到影响 所以应该往后放
        //2.负数小的应该排在前面 因为前缀和应该是先递增再递减 要递减的尽可能慢
        sort(nums.begin(),nums.end(),greater<int>());
        long long prefix = 0,ans = 0;//考虑溢出问题
        for (int val:nums) {
            prefix += val;
            if (prefix > 0) ans++;
        }
        return ans;
    }
};