/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

 

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true

*/

#include <iostream>
#include <string>
class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        int arr[26] = {0};
        if (ransomNote.size() > magazine.size()) return false;
        for (int elem:magazine) {
            arr[elem-'a']++;
        }
        for (int elem:ransomNote) {
            arr[elem-'a']--;
        }
        for (int elem:arr) {
            if (elem < 0) {
                return false;
            }
        }
        return true;
    }
};
int main() {

}