class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt = 0;
        for (char c:word) {
            if (isupper(c)) {
                cnt++;
            }
        }
        return cnt == 0 or cnt == n or cnt == 1 && isupper(word[0]);
    }
};