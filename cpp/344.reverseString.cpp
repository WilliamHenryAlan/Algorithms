
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int low = 0, high = s.size()-1;
        for (;low < high;low++,high--) {
            std::swap(s[low],s[high]);
        }
    }
};
#include <iostream>
int main() {

}