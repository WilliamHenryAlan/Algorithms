static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        int hash[26],n = s.size();
        memset(hash,0,sizeof(hash));
        for (char c:s) hash[c - 'a']++;
        for (int i = 0;i < n;i++) 
            if (hash[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
