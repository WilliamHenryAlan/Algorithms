class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int u = 0,d = n - 1,l = 0,r = n - 1,val = 1;
        while (1) {
            for (int i = l;i <= r;i++,val++) ans[u][i] = val;
            if (++u > d) break;
            for (int i = u;i <= d;i++,val++) ans[i][r] = val;
            if (--r < l) break;
            for (int i = r;i >= l;i--,val++) ans[d][i] = val;
            if (--d < u) break;
            for (int i = d;i >= u;i--,val++) ans[i][l] = val;
            if (++l > r) break;
        }
        return ans;
    }
};