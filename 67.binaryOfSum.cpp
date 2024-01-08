/**
 *              /2      %2
 * a    b   c   carry   ret
 * 0    0   0   0       0
 * 0    0   1   0       1
 * 0    1   0   0       1
 * 0    1   1   1       0
 * 1    0   0   0       1
 * 1    0   1   1       0
 * 1    1   0   1       0
 * 1    1   1   1       1
 * 包含a的位数b的位数和进位
 * 当有两个及以上的1才产生进位
 * 
 * solution:
 * 模拟二进制加法
 * 1.先把两个str反转 使低位在前
 * 2.补0 使两个str对齐
 * 3.结果的本位 = （加数+被加数+进位）%2
 * 4.进位 = （加数+被加数+进位）/2
 * 5.如果进位最后 == 1 说明溢出 要插入1
 * 6.反转 return
*/
#include <iostream>
#include <string>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::reverse(a.begin(),a.end());
        std::reverse(b.begin(),b.end());
        std::string ret;
        int temp;
        int ci_val = 0;
        int a_len = a.length(),b_len = b.length();
        while (a_len > b_len) {         //while (a_len > b_len++) 循环哪怕条件不满足 也会执行++操作 慎写
            b.push_back('0');
            b_len++;
        }
        while (b_len > a_len) {
            a.push_back('0');
            a_len++;
        }
        for (int i = 0;i < a_len;i++) {
            temp = a[i]-'0'+b[i]-'0'+ci_val;    //下标改代码要注意
            ci_val = temp/2;
            ret.push_back((char)(temp%2+'0'));  //'0'的ASCII为48
        }
        if (ci_val == 1) ret.push_back('1');
        std::reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main() {

}