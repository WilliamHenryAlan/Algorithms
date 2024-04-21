#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int,int> myMap;
        for (int val:nums) {
            myMap[val]++;
        }
        for (auto pair:myMap) {
            if (pair.second > len / 2) return pair.first;
        }
        return -1;
    }
};