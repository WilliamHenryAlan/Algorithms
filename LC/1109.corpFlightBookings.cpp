#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2,0);
        for (vector<int>& package:bookings) {
            int i = package[0],j = package[1],x = package[2];
            diff[i] += x;       //差分数组性质 区间内加[i,j] 只需要改变diff[i] += x和diff[j + 1] -= x
            diff[j + 1] -= x;
        }
        for (int i = 1;i < diff.size();i++) {
            diff[i] += diff[i - 1];
        }
        return {diff.begin() + 1,diff.end() - 1};
    }
};


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1,0);
        for (vector<int>& package:bookings) {
            int i = package[0],j = package[1],x = package[2];
            diff[i - 1] += x;
            diff[j] -= x;
        }
        for (int i = 1;i < diff.size();i++) {
            diff[i] += diff[i - 1];
        }
        diff.pop_back();
        return diff;
    }
};