class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(),n = t.size();
        if (m < n) return "";
        unordered_map<char,int> cnt_s,cnt_t;
        for (char ch:t) cnt_t[ch]++;            //把string映射到cnt_t
        int ans_l = -1,ans_r = m;               //初始化答案的左右index
        string ans;
        function<bool()> check = [&]() {        //判断cnt_s是否包含了cnt_t
            for (const pair<char,int>& pairs:cnt_t) {
                if (!cnt_s.contains(pairs.first)) return false;
                if (pairs.second > cnt_s.at(pairs.first)) return false;
            }
            return true;
        };
        for (int l = 0,r = 0;r < m;r++) {
            cnt_s[s[r]]++;                      //枚举右端点
            while (check()) {                   
                if (r - l < ans_r - ans_l) {    //当包含之后 更新最短的答案串
                    ans_l = l;
                    ans_r = r;
                }
                --cnt_s[s[l++]];                //移除左端点
            }
        }
        return ans_l == -1?"":s.substr(ans_l,ans_r - ans_l + 1);
    }
};
