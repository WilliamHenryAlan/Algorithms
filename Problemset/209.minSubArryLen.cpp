
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int minSubArrayLen(int target,std::vector<int>& nums) {
            if (nums[0]==target) return 1;
            int begin=0,end=0;
            int sum = 0,len = nums.size()+1,ret=len;
            while (end<nums.size())
            {
                sum += nums[end];
                while (sum>=target)
                {
                    len=end-begin+1;
                    if (len <= ret) ret=len;
                    sum  -= nums[begin];
                    begin++;
                }   
                end++;
            }
            if (len == nums.size()+1) return 0;
            return ret;
        }
};
/*
review 2024.2.6
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int ret = n+1;
        int r = 0;
        int l = 0;
        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                ret = min(ret,r-l+1);
                sum -= nums[l++];
            }
            r++;
        }
        return ret == n+1?0:ret;
    }
};