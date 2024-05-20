/**
 * issue:给一个string 返回最后一个单词长度
 * 
 * solution：
 * 反向遍历 返回最后一个单词的长度
 * 
*/
#include <iostream>
#include <string>
class Solution {
public:
    int lengthOfLastWord(std::string s) {
        if (s.length() == 0) return 0;
        int tailIndex = s.length()-1;
        while (s[tailIndex] == ' ') {   //去除尾部space
            tailIndex--;
        }
        int head = tailIndex;
        while (head >= 0 && s[head] != ' ') {   //tips:并列条件顺序不能反 否则test case = “a”时会出现越界
            head--;
        }
        return tailIndex-head;
    }   
};
int main() {

}