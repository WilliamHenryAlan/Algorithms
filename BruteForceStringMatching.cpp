/*
朴素模式匹配字符串

*/
#include <iostream>
#include <string>
int bruteForceStringMatching(std::string& mainString,std::string& subString) {
    int i = 0,j = 0;
    while (i < mainString.size()-subString.size()+1 and j < subString.size()) {
        if (mainString[i] == subString[j]) {
            ++i;
            ++j;
        }else {
            i = i-j+2;
            j = 0;
        }
    }
    if (j == subString.size()) {
        return i-j;
    }else {
        return -1;
    }
}
int main() {
    std::string mainString = "abaaabaabcaabcbab";
    std::string subString = "abaabc";
    int ret = bruteForceStringMatching(mainString,subString);
    std::cout << "return index = " << ret << std::endl;
}