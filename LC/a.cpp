#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int ans = 0;
        for (int l = 0,r = 0;r < s.size();r++) {
            auto iter = hash.find(s[r]);
            if (iter == hash.end()) {
                hash.insert(s[r]);
                ans = max(ans,r - l + 1);
            }
            while (hash.find(s[r]) != hash.end()) {
                l++;
            }
        }
        return ans;
    }
};
int main() {

}