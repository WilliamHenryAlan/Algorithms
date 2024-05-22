
#include <iostream>
#include <vector>
using namespace std;
/*
Method 1:模拟
1.去除首位空格
2.逆序遍历 找出每个单词

tips:
substr的用法 第一个参数为起始位置 第二个参数为长度
*/

class Solution {
public:
    string reverseWords(string s) {
        //预处理首位空格
        int i = 0,j = s.size() - 1;
        while (s[i] == ' ') i++;       
        while (s[j] == ' ') j--;
        //substr第一个参数为起始位置 第二个参数为长度
        string str = s.substr(i,j + 1 - i);
        //逆序分割单词反转
        string ret = "";
        int fast = str.size() - 1,slow = fast;
        while (fast >= 0) {
            while (fast >= 0 && str[fast] != ' ') fast--;   //fast寻找空格
            ret += str.substr(fast + 1,slow - fast) + " ";  //找到单词
            while (fast >= 0 && str[fast] == ' ') fast--;   //寻找下一个单词
            slow = fast;    //重置slow
        }
        ret.pop_back(); //去除末尾的空格
        return ret;
    }
};
/*
想要时间复杂度达到O(1)
1.先reverse整个string
2.分割单词 单个reverse
*/

int main() {
    std::string s = "     hello               ";
    Solution a;
    
    std::cout << a.reverseWords(s) << std::endl;
}