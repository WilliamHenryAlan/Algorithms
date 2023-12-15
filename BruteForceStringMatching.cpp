<<<<<<< HEAD
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
=======
/*
朴素模式匹配字符串 暴力破解
1.两个指针i j分别指向主串和模式串 一般情况下主串长度大于模式串
2.一共比较n-m+1次
3.匹配条件为i<mainString.size() and j<subString.size() 
        要遍历完才知道是否匹配 所以不能是i<mainString.size()-subString.size()+1 and j<subString.size()
4.当匹配成功时 j == subString.size()
5.如果单个char匹配成功 i++ j++
  如果匹配过程中失败 i指针要进行回溯 i = i-j+1 ,j=0
6.跳出循环后 如果匹配成功j == subString.size() return i-j为下标
               匹配失败 return -1 
*/
#include <iostream>
#include <string>
int bruteForceStringMatching(std::string& mainString,std::string& subString) {
    int i = 0,j = 0;
    while (i < mainString.size() and j < subString.size()) {
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
    std::string mainString = "mississippi";
    std::string subString = "issi";
    int ret = bruteForceStringMatching(mainString,subString);
    std::cout << "return index = " << ret << std::endl;
}
>>>>>>> 6c5e81194f4125fdad51ca233ccd425cc5cf7020
