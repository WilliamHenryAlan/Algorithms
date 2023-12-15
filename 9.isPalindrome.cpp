/*
判断是否为回文数
如果转化为字符串进行处理空间复杂度不为O(1)不行

1.如果是[0,9]都是回文数，负数必然不是
2.反转如果和原数字相等彼回文数 但是可能产生溢出
3.反转一半 如果是回文数 则相等
*/
#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >=0 && x <= 9) return true;
        if (x % 10 == 0 && x != 0) return false;    //个位为10的数字如果是回文数 开头必须是0 显然 只有0符合 eg：10 100 1000都不满足

        int compareNum = 0;
        while (compareNum < x) {
            compareNum = compareNum*10 + x % 10;
            x /= 10;
        }
        std::cout << "x = " << x << std::endl;
        std::cout << "compareNum = " << compareNum << std::endl;

        return x == compareNum/10 || x == compareNum;

    }
};

int main() {
    Solution s;
    int x = 123321;
    s.isPalindrome(x);
}

/*
与本体无关：
x/10算出有多少位
321 / 10^2 取出高位  
       321- （321 / 10^2）*10^2 去掉高位
       321 % 10               ‘          

*/