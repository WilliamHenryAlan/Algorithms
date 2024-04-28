
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        int boundary = INT_MAX / 10; //boundary为INT_MAX / 10 方便判断溢出
        int len = s.size(); //length
        int sign = 1; //1表示正 -1表示负 最后返回方便计算
        int sum = 0;  //累加
        int idx = 0;  //index
        //1.去除铅刀空格
        while (idx < len && s[idx] == ' ') idx++;
        if (idx == len) return 0;   //input:["       "]
        //2.判断符号 按照题意 可能是显式或者隐式如果有
        if (s[idx] == '-') sign = -1;   //隐式index不动
        if (s[idx] == '-' || s[idx] == '+') idx++; //显式只需要++ sign缺省为正(1)
        //3.遍历数值部分
        while (idx < len) {
            if (s[idx] < '0' || s[idx] > '9') break; //如果非数字break
            //还没有拼接
            //第一种情况：未拼接部分大于boundary 那么无论拼接多少 *10之后必然溢出
            //第二种情况：未拼接部分等于boundary 那么只有个位为 8或者9才溢出
            //tips不能写 >= 7因为INT_MIN 比 INT_MAX多一个 如果等于7 为INT_MIN + 1并没有溢出
            if (ret > boundary || ret == boundary && s[idx] > '7') 
                return sign == 1 ? INT_MAX : INT_MIN;
            ret = ret * 10 + (s[idx++] - '0');  //拼接
        }
        return sign * ret;//如果sign为bool最后要特殊判断
    }
};