/*
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false

*/

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