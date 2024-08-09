class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(),l = 0,r = 0,length = 1,index = 0,max_length = 0;
        for (int i = 0;i < n;i++) {
            l = i - 1;
            r = i + 1;
            while (l >= 0 && s[l] == s[i]) {
                length++;
                l--;
            }
            while (r < n && s[r] == s[i]) {
                length++;
                r++;
            }
            while (l >= 0 && r < n && s[l] == s[r]) {
                length += 2;
                l--;
                r++;
            }
            if (length > max_length) {
                max_length = length;
                index = l;
            }
            length = 1;
        }
        return s.substr(index + 1,max_length);
    }
};
