
/*
solution：
1.设置双指针指向字符串
2.t主串指针一直迭代 匹配成功则子串指针迭代
3.匹配成功则子串指针等于子串长度

prompt：
1.子序列和子串的区别
2.判断条件设置为i < tlen && j < slen
可以让两个str都为空时返回正确值 也可以让匹配完成后提前结束
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tlen = t.length();
        int slen = s.length();
        int i,j;
        for (i = 0,j = 0;i < tlen && j < slen;i++) {
            if (t[i] == s[j]) {
                j++;
            }
        }
        return j == slen;
    }
};