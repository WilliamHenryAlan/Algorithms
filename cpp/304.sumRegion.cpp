
#include <iostream>
#include <vector>
using namespace std;


class NumMatrix {
public:
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        /*
        计算preSum
        preSum[i][j]表示从[0,0]到[i - 1,j - 1]位置的子矩阵所有元素和
        preSum[i][j] = preSum[i][j - 1] + preSum[i - 1][j] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        */
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) return;
        //构造前缀和矩阵
        preSum.resize(m + 1,vector<int> (n + 1));
        for (int i = 1;i <= m;i++) {        //从1开始
            for (int j = 1;j <= n;j++) {
                preSum[i][j] = preSum[i][j - 1] + preSum[i - 1][j] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};
/*
print preSum
*/
int main() {
    vector<vector<int>> N {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix M(N);
    int m = N.size();
    int n = N[0].size();
    cout << "r/c ";
    for (int i = 0;i <= n;i++) {    //打印column index
        cout << i << "   "; 
    }
    cout << endl;
    for (int i = 0;i <= m;i++) {
        cout << i << ": [";         //打印row index
        for (int j = 0;j <= n;j++) {
            cout << M.preSum[i][j];
            if (j == n) break;  //最后一个数不打印空格
            if (M.preSum[i][j] / 10 == 0)
                cout << "   ";  //个位数打印3个space
            else cout << "  ";  //多位数打印2个space
        }
        cout << "]" << endl;
    }
}