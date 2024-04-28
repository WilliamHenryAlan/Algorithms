
#include <iostream>
#include <vector>
using namespace std;

/*
多了障碍物 相比62.不同路径1
说明dp公式需要有前提 当有障碍时
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[r-1][c-1] == 1) return 0;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for (int i = 0;i < r && obstacleGrid[i][0] == 0;i++) dp[i][0] = 1;
        for (int j = 0;j < c && obstacleGrid[0][j] == 0;j++) dp[0][j] = 1;
        for (int i = 1;i < r;i++) {
            for (int j = 1;j < c;j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[r-1][c-1];
    }
};


void print(int (&arr)[3][4]) {
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 4;j++) {
            cout << "[" << arr[i][j] << "]";
        }
        cout << endl;
    }
}
void print(vector<vector<int>>& twoDimensionalArray) {
    
}
int main() {
    int arr[3][4];
    int k = 0;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 4;j++) {
            arr[i][j] = k++;
        }
    }
    print(arr);
}



//desert version
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int r = obstacleGrid.size();
//         int c = obstacleGrid[0].size();
//         if (obstacleGrid[0][0] == 1 || obstacleGrid[r-1][c-1] == 1) return 0;
//         vector<vector<int>> dp(r, vector<int>(c, 0));
//         for (int i = 0;i < r && obstacleGrid[i][0] == 0;i++) {
//             dp[i][0] = 1;
//         } 
//         for (int j = 0;j < c && obstacleGrid[0][j] == 0;j++) {
//             dp[0][j] = 1;
//         }
//         for (int i = 1;i < r;i++) {
//             for (int j = 1;j < c;j++) {
//                 if (obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j-1] == 0)
//                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
//                 else if (obstacleGrid[i-1][j] != 0 && obstacleGrid[i][j-1] == 0)
//                     dp[i][j] = dp[i][j-1];
//                 else if (obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j-1] != 0)
//                     dp[i][j] = dp[i-1][j];
//                 else dp[i][j] = 0;
//             }
//         }
//         return dp[r-1][c-1];
//     }
// };