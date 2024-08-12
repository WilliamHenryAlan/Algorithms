/*
注意细节
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int u = 0,d = matrix.size() - 1,l = 0,r = matrix[0].size() - 1;
        while (1) {
            for (int i = l;i <= r;i++) ans.push_back(matrix[u][i]);//左到右
            if (++u > d) break;//更新边界
            for (int i = u;i <= d;i++) ans.push_back(matrix[i][r]);//上到下
            if (--r < l) break;
            for (int i = r;i >= l;i--) ans.push_back(matrix[d][i]);//右到左
            if (--d < u) break;
            for (int i = d;i >= u;i--) ans.push_back(matrix[i][l]);//下到上
            if (++l > r) break;
        }
        return ans;
    }
};

