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
    int x = 1111;
    std::cout << "Output = " << s.isPalindrome(x) << std::endl;
}

/*
与本题无关 想到的知识点：
x/10算出有多少位
321 / 10^2 取出高位  
       321- （321 / 10^2）*10^2 去掉高位
       321 % 10               ‘          

*/


/*
2023.12.17
solution:
因为是回文数 所以反转是一样的是回文数 但是考虑到溢出
可以用栈 或者转化为string 再反转 但是空间复杂度就不能达到O(1)
所以反转一半的数字


1.循环取数
    x%10可以取出低位 x/10可以丢弃低位
    取出的数字n 进行左移可以达到反转的目的
直到取出的数字n 大于等于 x的时候可以停止

2.无论x是奇数还是偶数 n的位数都可能大于或者等于x的位数
所以应该return n/10 == x || n == x 这两个条件满足一个就是回文数

3.因为是整数 所以负数肯定不是回文数 
10 100 1000这样的数回文数前面是带0的 所以只有0满足这一条件


*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 and x !=0) return false;    //如果不加这个条件 10 100 1000类似的数会判true
        int n = 0;
        while (n < x) {
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n/10 == x || n == x;
    }
};