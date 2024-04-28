#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        std::string str;
        for (char& c:s) {
            if (std::isalnum(c))    //数字或字母(ASCII在0~9 and 65~122)
                str += std::tolower(c);//去除非字母数字
        }
        int len = str.length();
        int l = 0,r = len-1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0,j = 0;
        while (j < len) {
            if (s[j] >= 'A' and s[j] <= 'Z' or s[j] >= 'a' and s[j] <= 'z' or s[j] >= '0' and s[j] <= '9') {
                s[i++] = std::tolower((s[j]));
            }
            ++j;
        }
        int l = 0,r = i-1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};