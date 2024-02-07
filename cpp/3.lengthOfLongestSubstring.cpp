
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0,r = 0;
        unordered_map<char,int> cnt;
        for (;r < s.size();r++) {
            cnt[s[r]]++;
            while (cnt[s[r]] > 1) {
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};