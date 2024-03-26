#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char,int> s_map;
        int ans = 0;
        for (int i = 0,j = 0;j < s.size();j++) {
            s_map[s[j]]++; //插入新元素
            auto iter = s_map.find(s[j]); //判断出现次数收否满足条件
            while (iter->second > 2) {
                s_map[s[i++]]--;
            }
            ans = max(ans,j - i + 1);
        }
        return ans;
    }
};