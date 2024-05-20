#include <iostream>
#include <vector>
using namespace std;
/*
greedy
1.可以算出每天的profit 累加所有的正数
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1;i < prices.size();i++) {
            res += max(prices[i] - prices[i-1],0);
        }
        return res;
    }
};