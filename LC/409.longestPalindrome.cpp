/*
构造最长回文串
1.出现偶数 分别放在string两侧
2.出现奇数 - 1 分别放在string两侧
3.如果s中有出现一次的char 放在中间
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0,flag = 0;
        unordered_map<char,int> hash;
        for (char c:s) hash[c]++;//统计字符出现次数
        for (auto& pair:hash) {
            int cnt = pair.second;
            if (cnt % 2 == 0)//even偶数
                ans += cnt;
            else {
                ans += cnt - 1;//odd奇数
                flag = 1;
            }
        }
        return ans + flag;
    }
};
