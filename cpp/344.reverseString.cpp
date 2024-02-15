#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size()-1;
        while (l < r) swap(s[l++],s[r--]);
    }
};

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int low = 0, high = s.size()-1;
        for (;low < high;low++,high--) {
            std::swap(s[low],s[high]);
        }
    }
};
