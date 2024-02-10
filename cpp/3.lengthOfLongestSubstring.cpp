
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
滑动窗口
1.遍历string 用hash存储每个char出现的次数
2.每次记录最大的length 当出现重复元素时 移动left去重
3.更新length = right - left + 1

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0,r = 0;
        unordered_map<char,int> cnt;
        int n = s.size();
        for (;r < n;r++) {
            cnt[s[r]]++;
            while (cnt[s[r]] > 1) {     //去重操作
                cnt[s[l]]--;            //先在hashTable中修改
                l++;                    //移动left
            }   
            ans = max(ans,r-l+1);       //uodate longest length
        }
        return ans;
    }
};