/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    let l = 0,r = 0,max_length = 0,ans = [],n = s.length,len = 1,start = 0;
    for (let i = 0;i < n;i++) {
        l = i - 1,r = i + 1;
        while (l >= 0 && s[l] == s[i]) {
            len++;
            l--;
        }
        while (r < n && s[r] == s[i]) {
            len++;
            r++;
        }
        while (l >= 0 && r < n && s[r] == s[l]) {
            len += 2;
            l--;
            r++;
        }
        if (len > max_length) {
            max_length = len;
            start = l;
        }
        len = 1;
    }
    return s.substr(start + 1,max_length);
};
