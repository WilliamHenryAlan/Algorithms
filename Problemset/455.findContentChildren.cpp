#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int slen = s.size();
        int glen = g.size();
        int i = 0;
        for (int j = 0;i < glen and j < slen;) {
            if (s[j] >= g[i]) {
                j++;
                i++;
            }else {
                j++;
            }
        }
        return i;
    }
};
/*
Method1 : greedy
1.局部最优：大饼干喂大胃口
*/
class Solution {
public:
    int findContentChildren(vector<int>& stomach, vector<int>& cookies) {
        std::sort(stomach.begin(),stomach.end());
        std::sort(cookies.begin(),cookies.end());
        int stomach_len = stomach.size();
        int cookies_len = cookies.size();
        int ans = 0;
        int j = cookies_len-1;
        for (int i = stomach.size()-1;i >= 0;--i) {
            if (j >= 0 and cookies[j] >= stomach[i]) {
                --j;
                ++ans;
            }
        }
        return ans;
    }
};