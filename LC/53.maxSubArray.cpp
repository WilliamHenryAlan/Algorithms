#include <iostream>
#include <vector>
using namespace std;

/*
动规：

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
           
    }
};

/*
greedy:
贪心策略：局部最优
        全局最优
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int count = 0;
        for (int i = 0;i < nums.size();i++) {
            count += nums[i];
            if (count > result) {
                result = count;
            }
            if (count < 0) {
                count = 0;
            }
        }
        return result;
    }
};