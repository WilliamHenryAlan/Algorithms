/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。


*/

/*
1.这道题要解决两个问题 1.去除多余空格
                  2.要把单词反转
2.反转单词 可以通过反转整个字符串之后 再进行单个word的反转 通过这种方式可以达到反转单词的目的 leetcode 反转字符串
3.去除多余空格想到 leetcode去除数组元素 先删去多余空格 再添加一个空格
4.具体实现：

5.最后slow会指向最后一个单词后的一个位置 所以return slow 就是新字符串的size

*/
#include <iostream>

class Solution {
public:
    void reverseStr(std::string& s,int begin,int end) {
        while (begin < end) {
            std::swap(s[begin++],s[end--]);
        }
    }
    void removeExtraSpaces(std::string& s) {
        int slow = 0,fast = 0;
        int len = s.size();
        for (;fast < len;fast++) {
            if (s[fast] != ' ') 
            {
                if (slow != 0) s[slow++] = ' ';
                while (fast < len and s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }
    std::string reverseWords(std::string s) {
        removeExtraSpaces(s);
        reverseStr(s,0,s.size()-1);
        int i = 0,j = 0;
        for (;j < s.size();j++) {
            if (s[j] == ' ') {
                reverseStr(s,i,j-1);
                j++;
                i = j;
            }
        }
        reverseStr(s,i,j-1);
        return s;
    }
};
int main() {
    std::string s = "t";
    Solution a;
    std::cout << s.size() << std::endl;
    a.reverseStr(s,0,s.size()-1);
    std::cout << s << std::endl;
}