#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> diffArr(10,0);
        for (auto& query:nums) {
            diffArr[query[0]] += 1;
            diffArr[query[1] + 1] -= 1;
        }
        int ans = 0;
        for (int i = 1;i < diffArr.size();i++) {
            diffArr[i] += diffArr[i - 1];
        }
        for (int& val:diffArr) {
            if (val > 0) ans++;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> test = {{28,88},{9,88},{52,100},{4,86},{26,70},{43,81},{66,94},{15,74},{10,15},{17,54},{65,73},{70,100},{4,61},{78,93},{78,95},{42,59},{99,100},{78,97},{39,72},{2,83},{23,54},{14,94},{50,59},{43,56},{50,80},{57,75},{59,75},{50,59},{83,85},{82,99},{38,75},{49,51},{17,27},{69,96},{1,13},{1,84},{14,68},{23,36},{7,41},{72,80},{2,4},{17,53},{54,82},{10,83}};
    cout << test.size();
}

