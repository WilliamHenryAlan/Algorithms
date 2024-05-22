#include<iostream>
#include <vector>
using namespace std;
/*
Method 1
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(),nums.end()); //先反转整个nums
        reverse(nums.begin(),nums.begin() + k); //按照k分成前后两个nums 分别进行反转
        reverse(nums.begin() + k,nums.end());
    }
};