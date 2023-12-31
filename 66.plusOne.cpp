/**
 * solution：
 * 将vector转换为int类型会溢出 所以不考虑
 * 1.如果不进位 最后一个元素++之后return
 * 2.如果进位 把当前assign为0 向前进位 如果不等于9 则++之后return
 *                                  如果等于9 则继续进位
 * 3.如果进位到index0 则要在头部insert一个element = 1之后return
 * 
*/
#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int len = digits.size();
        if (digits[len-1]++ != 9) {
            return digits;
        }
        digits[len-1] = 0;
        int i = len-2;
        while (i >= 0) {
            if (digits[i] == 9) {
                digits[i] = 0;
            }else {
                digits[i]++;
                return digits;
            }
            i--;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};