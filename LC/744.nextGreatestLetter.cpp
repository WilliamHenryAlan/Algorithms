//upper_bound
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0,r = letters.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (letters[m] > target) r = m - 1;
            else l = m + 1;
        }
        if (l == letters.size()) return letters[0];//防止越界
        return letters[l];
    }
};