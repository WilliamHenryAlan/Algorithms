#include <iostream>
/*
review 2024.2.26
*/
class Solution {
public:
    int mySqrt(int x) {
        //特殊判断
        if (x == 0) return 0;
        if (x == 1) return 1;
        int l = 1,r = x / 2 + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            //防止溢出 用除法
            if (m == x / m) return m;
            else if (m > x / m) r = m;
            else l = m + 1;
        }
        //eg:x = 8 循环结束后l = 3
        return l - 1;
    }
};
/*
不使用内置函数算出x的平方根
solution；
用二分查找 0~x中 mid*mid <= x
*/
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