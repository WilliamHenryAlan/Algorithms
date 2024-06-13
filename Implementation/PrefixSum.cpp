/*
前缀和：
*/
#include <iostream>
#include <vector>
using namespace std;

class PrefixSum {
public:
    vector<int> preSum;
public:
    /*
    构造前缀和数组
    */
    PrefixSum(vector<int>& nums) {
        this->preSum.resize(nums.size() + 1,0);
        for (int i = 1;i <= nums.size();i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }
    /*
    左闭右闭求区间和
    */
    int section(int begin,int end) {
        return preSum[end + 1] - preSum[begin];
    }
};
class NumMatrix {
    // 定义：preSum[i][j] 记录 matrix 中子矩阵 [0, 0, i-1, j-1] 的元素和
public:
    vector<vector<int>> preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return;
        // 构造前缀和矩阵
        preSum = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 计算每个矩阵 [0, 0, i, j] 的元素和
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i - 1][j - 1] - preSum[i-1][j-1];
            }
        }
    }
    
    // 计算子矩阵 [x1, y1, x2, y2] 的元素和
    int sumRegion(int x1, int y1, int x2, int y2) {
        // 目标矩阵之和由四个相邻矩阵运算获得
        return preSum[x2+1][y2+1] - preSum[x1][y2+1] - preSum[x2+1][y1] + preSum[x1][y1];
    }
};

void print(const std::vector<int>& vi);

int main() {
    vector<int> arr{1, 7, 3, 6, 5, 6};
    print(arr);
    PrefixSum prefixSumArray(arr);
    print(prefixSumArray.preSum);
    cout << "[2,3] = " << prefixSumArray.section(2,3) << endl;

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
    for (int i = 0;i <= n;i++) {
        cout << i << "   "; 
    }
    cout << endl;
    for (int i = 0;i <= m;i++) {
        cout << i << ": [";
        for (int j = 0;j <= n;j++) {
            cout << M.preSum[i][j];
            if (j == n) break;
            if (M.preSum[i][j] / 10 == 0)
                cout << "   ";
            else cout << "  ";
        }
        cout << "]" << endl;
    }

}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}