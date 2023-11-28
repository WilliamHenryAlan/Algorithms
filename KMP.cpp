/*
KMP是对BuruteForceMatching的优化
KMP算法的思想：
1.因为主串的内容我们不知道 所以每次匹配失败 主串的指针都要进行回溯 是暴力算法的思想
2.但是匹配过程中 我们是知道匹配过的子串的 可以进行利用 
    而且匹配过的子串 直到匹配失败子串之前的所有字符 都是和模式串相等的
    这样就可以跳过一部分子串的匹配 从而使i不用进行回溯 
    并且模式串也可以跳过几个字符
3.KMP算法相对比暴力 可以发现 优化的地方在于 匹配失败时主串不需要回溯
暴力：O(mn)
KMP：O(m+n)

求next数组：
1.可以看出next数组和模式串有关 和主串无关 先进行初始化
    i为后缀末 = subString.size()-1
    j为前缀末 = 0
2.当前后缀匹配的情况
    j++
3.当前后缀不匹配的情况


example：abc
前缀：包含首字母不包含尾字母的子串 a，ab
后缀：包含尾字母不包含首字母的子串 c，bc

*/
#include <iostream>
#include <string>
#include <vector>
void getNext(const std::string& pattern, std::vector<int>& next);
void getNext_better(const std::string& pattern, std::vector<int>& next);
int KMP(std::string& mainString,std::string& subString,std::vector<int>& next);
int main() {
    std::string mainString = "mississippi";
    std::string subString = "issi";
    std::vector<int> next(subString.size(),0);
    getNext(subString,next);
    int ret = KMP(mainString,subString,next);
    std::cout << "return index = " << ret << std::endl;
}
int KMP(std::string& mainString,std::string& subString,std::vector<int>& next) {
    int i = 0,j = 0;
    while (i < mainString.size() and j < subString.size()) {
        if (mainString[i] == subString[j]) {
            i++;
            j++;
        }else {
            if (j == 0) {
                i++;
            }else {
                j = next[j];
            }
        }
    }
    if (j == subString.size()) {
        return i-j;
    }else {
        return -1;
    }
}
void getNext(const std::string& pattern, std::vector<int>& next) {
    next[0] = -1;
    int i = pattern.size()-1;
    int j = 0;
    while (j < pattern.size()) {
        if ()
    }



    next[0] = -1;                   // 初始化next数组第一个元素为-1
    int k = -1;                     // k记录当前匹配的前缀的最长公共前后缀的长度
    int j = 0;                      // j是当前匹配的后缀的位置
    while (j < pattern.size() - 1) {             // 循环计算next数组
        if (k == -1 || pattern[j] == pattern[k]) {      // 如果当前字符匹配成功
            ++k;                    // 前缀的最长公共前后缀长度加一
            ++j;                    // 匹配的后缀位置加一
            next[j] = k;            // 将next[j]赋值为k
        } else {
            k = next[k];            // 如果匹配失败，更新k为next[k]
        }
    }
}

void getNext_better(const std::string& pattern, std::vector<int>& next) {
    int n = pattern.length();
    int k = -1;                     // k记录当前匹配的前缀的最长公共前后缀的长度
    int j = 0;                      // j是当前匹配的后缀的位置
    next[0] = -1;                   // 初始化next数组第一个元素为-1
    while (j < n - 1) {             // 循环计算next数组
        if (k == -1 || pattern[j] == pattern[k]) {      // 如果当前字符匹配成功
            ++j;                    // 后缀位置加一
            ++k;                    // 前缀的最长公共前后缀长度加一
            if (pattern[j] != pattern[k]) {             // 如果下一位不相等
                next[j] = k;                            // 将next[j]赋值为k
            } else {
                next[j] = next[k];                      // 如果下一位相等，将next[j]赋值为next[k]
            }
        } else {
            k = next[k];            // 如果匹配失败，更新k为next[k]
        }
    }
}