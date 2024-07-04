/*
brute force
1.textString下标i和pattern下标j初始化为0
2.循环比较字符直到textString或者pattern其中一个遍历结束
    如果text[i] == pattern[j] 则后移i++ j++
    如果匹配失败 回溯i = i - j + 1  , j = 0
3.
    1.如果textString遍历完还没结果 说明没找到匹配 return -1
    2.如果pattern遍历完了 说明找到匹配 return i - j


前后缀概念：
    example：abc
    前缀：包含首字母不包含尾字母的子串 a，ab
    后缀：包含尾字母不包含首字母的子串 c，bc
    前后缀不能包括字符串本身 abc不能是abc的前缀或者后缀

KMP是对BuruteForceMatching的优化
KMP算法的思想：
1.因为主串的内容我们不知道 所以每次匹配失败 主串的指针都要进行回溯 是暴力算法的思想
2.但是匹配过程中 我们是知道匹配过的子串的 可以进行利用 
    而且匹配过的子串 直到匹配失败子串之前的所有字符 都是和模式串相等的
    这样就可以跳过一部分子串的匹配 从而使i不用进行频繁回溯 
    并且模式串也可以跳过几个字符

暴力：O(mn)
KMP：O(m+n)

总结：KMP的textString指针不回溯 patternString指针滑动到新位置k k仅与pattern有关
getNext:


*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int bruteForce1(const std::string& text, const std::string& pattern) {
    int i = 0,j = 0;
    while (i < text.size()) {
        while (j < pattern.size() && text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == pattern.size()) return i - j;
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    return -1;
}

int bruteForce2(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) return 0; // 如果模式字符串为空，返回0
    if (text.size() < pattern.size()) return -1; // 如果文本长度小于模式长度，直接返回-1
    int i = 0, j = 0;
    while (i < text.size() && j < pattern.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == pattern.size()) return i - j;
    return -1;
}

std::vector<int> getNext(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> next(m);
    next[0] = -1;  // 设为-1
    int i = 0,j = -1;
    while (i < m) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else j = next[j];
    }
    print(next);
    return next;
}

int KMP(const std::string& text, const std::string& pattern,const vector<int>& next) {
    if (pattern.empty()) return 0; // 如果模式字符串为空，返回0
    if (text.size() < pattern.size()) return -1; // 如果文本长度小于模式长度，直接返回-1
    int i = 0, j = 0;
    while (i < text.size() && j < pattern.size()) {
        if (j == -1 || text[i] == pattern[j]) { //对比bf改变
            i++;
            j++;
        } else {
            j = next[j];    //对比bf改变
        }
    }
    return i - j;
}
// int KMP(const std::string& text, const std::string& pattern,const vector<int>& next) {
// 	if (pattern.empty()) return 0; // 如果模式字符串为空，返回0
// 	if (text.size() < pattern.size()) return -1; // 如果文本长度小于模式长度，直接返回-1
// 	int i = 0, j = 0;
// 	int n = text.size();
// 	int m = pattern.size();
// 	while (i < n && j < m) {
// 		if (j == -1 || text[i] == pattern[j]) { //对比bf改变
// 			i++;
// 			j++;
// 		} else {
// 			j = next[j];    //对比bf改变
// 		}
// 	}
// 	return i - j;
// }


// int KMP(const std::string& text, const std::string& pattern,const vector<int>& next) {
//     if (pattern.empty()) return 0; // 如果模式字符串为空，返回0
//     if (text.size() < pattern.size()) return -1; // 如果文本长度小于模式长度，直接返回-1
//     int i = 0, j = 0;
//     while (i < text.size()) {
//         if (j == -1 || text[i] == pattern[j]) { //对比bf改变
//             i++;
//             j++;
//             if (j == pattern.size()) return i - j;
//         } else {
//             j = next[j];    //对比bf改变
//         }
//     }
//     return -1;
// }



int main() {
    std::string mainString = "mississsippi";
    std::string subString = "sssi";
    int ret = bruteForce2(mainString,subString);
    std::cout << "return index = " << ret << std::endl;

    std::vector<int> next;
    next = getNext(subString);
    std::cout << "return index = " << KMP(mainString,subString,next) << std::endl;
}
