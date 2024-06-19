
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
/*
review 2024.2.23
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> record;
        int cnt = 0;
        int ret = 0;
        for (int j = 0,i = 0;j < s.size();j++) {
            record[s[j]]++;
            cnt++;
            while (record[s[j]] > 1) {
                record[s[i++]]--;
                cnt--;
            }
            ret = max(cnt,ret);
        }
        return ret;
    }
};
/*
review 6.19
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int ans = 0;
        for (int l = 0,r = 0;r < s.size();r++) {
            while (hash.find(s[r]) != hash.end()) {
                hash.erase(s[l]);
                l++;
            }
            hash.insert(s[r]);
            ans = max(ans,r - l + 1);
        }
        return ans;
    }
};