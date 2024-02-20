
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Method: 1:差分数组 array
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int len = trips.size();
        vector<int> arr(1001,0);
        for (int i = 0;i < len;i++) {
            int nums = trips[i][0], from = trips[i][1], to = trips[i][2];
            arr[from] += nums;
            arr[to] -= nums;
        }
        int c = 0;
        for (int& val:arr) {
            if (c > capacity) return false;
            c += val;
        }
        return true;
    }
};
/*
Method: 2:差分数组 map
*/
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int> mp;
        int len = trips.size();
        for (vector<int>& package:trips) {
            int nums = package[0],from = package[1], to = package[2];   //记录上车下车的人 from为上车 to为下车
            mp[from] += nums;   //上车+
            mp[to] -= nums;     //下车-
        }
        int cnt = 0;
        for (int i = 0;i < mp.size();i++) { //hash遍历是无序的 可以使用map用pair<int,int>进行遍历
            if (cnt > capacity) return false;
            cnt += mp[i];
        }
        return true;
    }
};