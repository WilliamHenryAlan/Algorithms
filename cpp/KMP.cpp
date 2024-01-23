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
void getNext(std::string& subString,std::vector<int>& next) {

}
int KMP(const std::string& mainString,const std::string& subString,std::vector<int>& next) {
    int mainlen = mainString.length();
    int sublen = subString.size();
    int i = 0,j = 0;
    有错的
    while (i < mainlen && j < sublen) {
        if (mainString[i] == subString[j]) {    //继续匹配后序字符
            j++;
        }else {
            j = next[j];        //匹配失败 模式串回溯
        }
        i++;
    }
    if (j == sublen) {
        return i-j;
    }else {
        return -1;
    }
}

int main() {
    std::string mainString = "mississippi";
    std::string subString = "issi";
    std::vector<int> next;
    getNext(subString,next);    //Create next array

    int ret = KMP(mainString,subString,next);
    std::cout << "return index = " << ret << std::endl;
}

