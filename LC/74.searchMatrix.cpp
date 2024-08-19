
把二维数组映射为一维数组 用二分 时间复杂度可以达到 log(m * n) 但是不需要真的转化为一维数组
 nums[i] = matrix[i / n][i % n]  n为matrix[0].size() 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        for (int i = 0;i < n;i++) for (int j = 0;j < m;j++) if (matrix[i][j] == target) return true;return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int r = matrix.size() * n - 1,l = 0;
        int val,m;
        while (l <= r) {
            m = l + (r - l) / 2;
            val = matrix[m / n][m % n];
            if (target == val) return true;
            target > val ? l = m + 1:r = m - 1;
        }
        return false;
    }
};