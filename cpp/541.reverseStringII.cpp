/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

    如果剩余字符少于 k 个，则将剩余字符全部反转。
    如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

 

示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：

输入：s = "abcd", k = 2
输出："bacd"

*/

/*
solution:
1.题意为计数2k个substring 然后 reverse(substring) 所以for循环的i可以为i += 2 * k
2.写子程序 反转字符串 一般写为左闭右开区间 这样刚好配合传入需要反转的substring头尾(i,i+k)
3.因为传给reverseString的头尾i+k是要>i的 所以条件可以为i+k <= s.size() 考虑边界情况
4.如果i+k > s.size()说明不够2k个 就传入(i,i.size())并反转
5.return
*/
#include <iostream>
#include <string>
class Solution {
public:
    void reverseString(std::string& s,int begin,int end) {
            int low = begin, high = end-1;
            for (;low < high;low++,high--) {
                std::swap(s[low],s[high]);
            }
        }
    std::string reverseStr(std::string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k)
        {
            if (i+k <= s.size()) {
                reverseString(s,i,i+k);
            }else {
                reverseString(s,i,s.size());
            }
        }
        return s;

    }
};
int main() {

}