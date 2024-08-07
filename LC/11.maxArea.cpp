#include <iostream>
#include <vector>
using namespace std;
//method 1:brute force
//会超出时间限制 O(n^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int len = height.size();
        if (len < 2) return 0;
        for (int i = 0;i < len-1;i++) {
            for (int j = i+1;j < len;j++) {
                ret = std::max(std::min(height[i],height[j]) * (j-i),ret);
            }
        }
        return ret;
    }
};
//method 2:double pointer
/*

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int len = height.size();
        if (len < 2) return 0;
        int left = 0,right = len-1;
        while (left < right) {
            ret = std::max(ret,std::min(height[left],height[right])*(right-left));
            if (height[left] < height[right]) {
                left++;
            }else {
                right--;
            }
        }
        return ret;
    }
};
/*
review 2024.6.18
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0,ret = 0;
        int n = height.size();
        for (int l = 0,r = n - 1;l < r;) {
            ans = min(height[l],height[r]) * (r - l);
            ret = max(ans,ret);
            if (height[l] >= height[r]) {
                r--;
            }else {
                l++;
            }
        }
        return ret;
    }
};
/*
2024.8.1
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(),l = 0,r = n - 1,ans = 0;
        while (l < r) {
            ans = max(ans,min(height[l],height[r]) * (r - l));
            if (height[l] >= height[r]) r--;
            else l++;
        }
        return ans;
    }
};