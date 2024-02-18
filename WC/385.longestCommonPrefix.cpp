#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ret = 0;
        set<int> myset;
        for (int i = 0;i < arr1.size();i++) {
            int temp = arr1[i];
            while (temp) {
                myset.insert(temp);
                temp /= 10;
            }
        }
        for (int j = 0;j < arr2.size();j++) {
            int temp = arr2[j];
            int num = 0;
            while (temp) {
                auto iter = myset.find(temp);
                if (iter != myset.end()) {
                    num = *iter;
                    break;
                }
                temp /= 10;
            }
            int len = 0;
            while (num) {
                len++;
                num /= 10;
            }
            ret = max(len,ret);
        }
        return ret;
    }
};



int main() {
    Solution s;
    vector<int> a{1,10,100}; 
    vector<int> b{1000}; 
    s.longestCommonPrefix(a,b);
}