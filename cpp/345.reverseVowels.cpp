#include <iostream>
#include <string>
using namespace std;

/*
tips:静态变量分为:   
                1.静态成员变量
                2.静态局部变量

*/
class Solution {
public:
    static const std::string vowels;
    string reverseVowels(string s) {
        int len = s.size();
        int left = 0,right = len-1;
        while (left < right) {
            while (left < right and vowels.find(s[left]) == std::string::npos) left++;
            while (left < right and vowels.find(s[right]) == std::string::npos) right--;
            if (left < right) {
                std::swap(s[left++],s[right--]);
            }
        }
        return s;
    }
};
const std::string Solution::vowels = "aeiouAEIOU";

int main() {
    Solution a;
    return 0;
}
//比较暴力的写法:
// class Solution {
// public:
//     string reverseVowels(string s) {
//         int len = s.size();
//         int left = 0,right = len-1;
//         while (left < right) {
//             while (s[left] != 'a' and s[left] != 'e' and s[left] != 'i' and s[left] != 'o' and s[left] != 'u' 
//             and s[left] != 'A' and s[left] != 'E' and s[left] != 'I' and s[left] != 'O' and s[left] != 'U' 
//             and left < right)left++;
//             while (s[right] != 'a' and s[right] != 'e' and s[right] != 'i' and s[right] != 'o' and s[right] != 'u' 
//             and s[right] != 'A' and s[right] != 'E' and s[right] != 'I' and s[right] != 'O' and s[right] != 'U' 
//             and left < right)right--;
//             if (left < right) {
//                 std::swap(s[left++],s[right--]);
//             }
//         }
//         return s;
//     }
// };