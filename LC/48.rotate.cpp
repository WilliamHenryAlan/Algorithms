1.原始矩阵
[[5,1,9,11],
[2,4,8,10],
[13,3,6,7],
[15,14,12,16]]
2.矩阵上下翻转
[[15,14,12,16]
[13,3,6,7],
[2,4,8,10],
[5,1,9,11],]
3.沿着对角线反转元素
[[15,13,2,5]
[14,3,4,1],
[12,6,8,9],
[16,7,10,11],]

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(),m = n / 2 - 1;
        for (int i = 0;i <= m;i++) swap(matrix[i],matrix[n - 1 - i]);
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

