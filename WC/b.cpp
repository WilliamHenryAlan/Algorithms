#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> hash;
        for (int& i:nums) {
            hash[i]++;
        }
        for (pair<const int,int>& p:hash) {
            if (p.second > 2) return false;
        }
        return true;
    }
};