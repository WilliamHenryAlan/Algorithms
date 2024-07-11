/*
平均出现次数为m = s.size() / 4
1.当有字符出现次数 > m时 无论怎么替换 都不能达到balanced string
2.当滑动窗口外的字符出现次数 <= m时 通过替换 可以达到balanced string
*/
class Solution {
public:
    int balancedString(string s) {
        int n = s.size(),m = n / 4,cnt[90];//空间可以存储四个char就行 hash or array 存储'Q', 'W', 'E', 'R' 四种字符出现次数
        for (char c:s) cnt[c]++;//记录次数
        if (cnt['Q'] == m && cnt['W'] == m &&cnt['E'] == m &&cnt['R'] == m) return 0;//如果已经达到balanced string return
        int l = 0,r = 0,ans = n;
        for (;r < n;r++) {
            cnt[s[r]]--;//初始化l和r = 0时 第一个元素已经在滑动窗口中了
            while (cnt['Q'] <= m && cnt['W'] <= m &&cnt['E'] <= m &&cnt['R'] <= m) {
                ans = min(ans,r - l + 1);//满足替换之后可以达到balanced string的条件 记录最短长度
                cnt[s[l++]]++;
            }
        }
        return ans;
    }
};