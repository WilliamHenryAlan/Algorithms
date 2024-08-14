class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size(),ans = 0;
        for (int i = 0;i < n;++i) {
            if (forts[i] == 1) {
                int cnt = 0;
                for (int j = i - 1;j >= 0;j--) {
                    if (forts[j] == 0) cnt++;
                    else if (forts[j] == -1) {
                        ans = max(ans,cnt);
                        break;
                    } 
                    else break;
                }
                cnt = 0;
                for (int j = i + 1;j < n;j++) {
                    if (forts[j] == 0) cnt++;
                    else if (forts[j] == -1) {
                        ans = max(ans,cnt);
                        break;
                    } 
                    else break;
                }
            }
        }
        return ans;
    }
};
