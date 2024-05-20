/*
issue:
判读s字符串s是不是为 字符串数组的单词的首写字母 缩略词
solution：
for循环暴力
*/
#include <iostream>
#include <vector>
class Solution {
public:
    bool isAcronym(std::vector<std::string>& words, std::string s) {
        int len = s.size();
        if (len != words.size()) return false;
        for (int i = 0;i < len;i++) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};