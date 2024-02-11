
#include <iostream>
#include <vector>
using namespace std;

//修改
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer(matrix);
        int r,c;
        for (c = 0;c < answer[0].size();c++) {
            int temp = -1;
            for (r = 0;r < answer.size();r++) {
                temp = max(answer[r][c],temp);
            }
            for (int k = 0;k < answer.size();k++) {
                if (answer[k][c] == -1) {
                    answer[k][c] = temp;
                }
            }
        }
        return answer;
    }
};

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer(matrix);
        int r,c;
        for (c = 0;c < answer[0].size();c++) {
            int temp = -1;
            for (r = 0;r < answer.size();r++) {
                temp = max(answer[r][c],temp);
            }
            for (int k = 0;k < answer.size();k++) {
                if (answer[k][c] == -1) {
                    answer[k][c] = temp;
                }
            }
        }
        return answer;
    }
};