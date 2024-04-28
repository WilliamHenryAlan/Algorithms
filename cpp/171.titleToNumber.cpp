#include <iostream>
#include <string>
using namespace std;
/*
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 


输入: columnTitle = "ZY"
输出: 701
*/
/*
每一位的位权为26^multiple次

*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int size = columnTitle.size();
        int multiple = 0;
        for (int i = size-1;i >= 0;--i) {
            ans += (columnTitle[i] - 64)*std::pow(26,multiple++);
        }
        return ans;
    }
};

