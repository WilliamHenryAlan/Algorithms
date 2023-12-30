#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int len = digits.size();
        if (digits[len-1]++ != 9) {
            return digits;
        }
        
    }
};