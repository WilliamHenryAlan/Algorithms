#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> hash;
        for (int val:nums) {
            hash[val]++;
            if (hash[val] > nums.size() / 2) return val;
        }
        return nums[0];
    }
};