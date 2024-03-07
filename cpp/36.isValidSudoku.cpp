#include <iostream>
#include <vector>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //第一维表示第几行 or 第几列 or 第几个box
        //第二个维度设置为10是为了和char1~9对应 方便处理
        int row[9][10] {0}; //检查行是否重复
        int column[9][10] {0};  //检查列是否重复
        int box[9][10] {0}; //检查9个box中是否存在重复
        for (int i = 0;i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';    //因为第二维设置为10 直接减去'0'就是对应的数字
                if (row[i][num]) return false;    //init为0 if(row[i][j] != 0) 说明重复出现数字
                if (column[j][num]) return false;
                if (box[3 * (i / 3) + j / 3][num]) return false;
                //如果第一次出现 进行assignment
                row[i][num] = 1;
                column[j][num] = 1;
                box[3 * (i / 3) + j / 3][num] = 1;
            }
        }
        return true;
    }
};