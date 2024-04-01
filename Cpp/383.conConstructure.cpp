

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