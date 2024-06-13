/*
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
3.KMP算法相对比暴力 可以发现 优化的地方在于 匹配失败时主串不需要频繁回溯
暴力：O(mn)
KMP：O(m+n)

求next数组：
    对于给定的pattern 长度为n
    则 int next[n + 1]
    
1.可以看出next数组和模式串有关 和主串无关 先进行初始化
    i为后缀末 = subString.size()-1
    j为前缀末 = 0
2.当前后缀匹配的情况
    j++
3.当前后缀不匹配的情况



*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;




int main() {
    std::string mainString = "mississippi";
    std::string subString = "issi";
    std::vector<int> next;
    getNext(subString,next);    //Create next array

    int ret = KMP(mainString,subString,next);
    std::cout << "return index = " << ret << std::endl;
}

//O(n)求next 
void getNext

//O(n^2)求next
void getNext(std::vector<int>& next,string& pattern) {
    int n = pattern.size();
    next.assign(n + 1,0);
    //next[0] = 0,next[1] = 0 pattern为空或者只包含一个字符时 最长公共前缀为0
    for (int i = 2;i <= n;i++) {
        string temp = pattern.substr(0,i);
        for (int suffix_position = i - 1;suffix_position >= 1;suffix_position--) {
            if (temp.substr(0,suffix_position) == temp.substr(i - suffix_position,suffix_position)) {
                next[i] = suffix_position;
                break;
            }
        }
    }
}

