/*
不使用内置函数算出x的平方根
solution；
用二分查找 0~x中 mid*mid <= x
*/
#include <iostream>
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        while (low <= high) {
            long long mid = (low+high)/2;
            if (mid*mid == x) {
                return mid;
            }else if (mid*mid > x) {
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return low-1;
    }
};