/*
issue:求第一个出现的子串下标
solution：
字符串匹配问题 想到用KMP算法 主串指针不用进行回溯
*/
#include <iostream>
#include <string>
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        
    }
};

/*
Solution:
1.因为要涉及遍历 想到双指针 i j 分别指向 haystack needle两个string的下标index0的位置
2.循环遍历haystack 每次迭代i
3.循环比较两个字符串的字符 当遇到有第一个相同匹配的字符时 并且 此时j没有到needle的最后一个‘\0'时 迭代两个指针进行match
4.循环结束分为匹配成功和失败两个情况
    j指向needle的最后一个char '\0'时 表示匹配成功 return i-j
    如果失败将要回溯mainstring的指针i = i - j 因为每次循环都会迭代i = i - j 并重置j=0 
     
*/
#include <iostream>
#include <string>
class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int slen=haystack.size(),tlen=needle.size();
        int s=0,t=0;
        for (;s<slen;s++)
        {
            while (haystack[s]==needle[t] and needle[t]!= '\0') //std::string 是stl封装的 内部还是char* 所以最后也是有'\0'
            {
                s++;
                t++;
            }
            if (needle[t] == '\0')
            {
                return s-t;
            }
            else
            {
                s=s-t;
                t=0;
            }
        }
        return -1;
    }
};
int main()
{
    std::string s="sadfdjks",t="sad";
    Solution a;
    std::cout << "output = " << a.strStr(s,t) << std::endl;
}