#include<iostream>
#include <vector>
using namespace std;
/*
> 用字符串数组来模拟
1. 考虑特殊情况 当行数不足3行时 直接return
2. 每次i迭代都是i += flag
    - 当flag = 1时 i递增 
    - 当flag = -1时 i递减
这样就可以实现 到达上下边界的时候 实现遍历方向的转变
3. 初始化flag == -1 第一次进入 会被转化为1 这样就是递增的情况
4. 当到达下边界 也就是numRows - 1时 进入if 此时 flag被取反

*/
class Solution {
public:
    string convert(string s, int numRows) {
        //当numRows小于两行时 直接return
        if (numRows < 2) return s;
        vector<string> Rows(numRows);//用每一行为string模拟过程
        //用flag转化符号 使遍历到0向下遍历
        //              遍历到numRows - 1时 向上遍历
        int flag = -1;  //初始化为-1
        int i = 0;
        for (char c:s) {
            Rows[i].push_back(c);
            if (i == 0 || i == numRows - 1) {
                flag = -flag;
            }
            i += flag;
        }
        string ret;
        for (const string& str:Rows) {
            ret += str;
        }
        return ret;
    }
};