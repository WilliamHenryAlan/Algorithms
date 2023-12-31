/**
 * 
 * a    b   c
 * 0    0   0   0
 * 0    0   1   1
 * 0    1   0   1
 * 0    1   1   10
 * 1    0   0   1
 * 1    0   1   10
 * 1    1   0   10
 * 1    1   1   11
 * 包含a的位数b的位数和进位
 * 当有两个及以上的1才产生进位
 * 
 * 
*/
#include <iostream>
#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int temp;
        int ai = 0,bi = 0,ci_val = 0;
        int a_len = a.length(),b_len = b.length();
        for (;ai < a_len && bi < b_len;ai++,bi++) {
            temp = a[ai]-'0'+b[bi]-'0'+ci_val;

        }
    }
};
