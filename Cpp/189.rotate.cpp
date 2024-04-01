#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = k;
        int i = nums.size() - 1;
        while (k--) {
            nums.insert(nums.begin(),nums[i]);
        }
        nums.resize(nums.size() - temp);
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
    }
};