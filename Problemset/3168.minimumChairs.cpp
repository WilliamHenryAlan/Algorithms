class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int temp = 0;
        for (char c:s) {
            if (c == 'E') {
                temp++;
                ans = max(ans,temp);
            }else {
                temp--;
            }
        }
        return ans;
    }
};
