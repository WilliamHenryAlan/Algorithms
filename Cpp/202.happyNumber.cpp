/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

    对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    如果这个过程 结果为 1，那么这个数就是快乐数。

如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

 

示例 1：

输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

示例 2：

输入：n = 2
输出：false

*/

/*
solution：
因为快乐数求和判定只能是1或者循环 所以想到hashtable 通过unorder_set去重
1.正数%10可以取低位 然后通过/10去低位 循环操作 可以取得每个位
2.构造getSum函数 返回快乐数的和
3.循环 每次把结果传入getSum函数 并返回 判断如果是1 return true 
4.如果在set中找到数字 说明已经进入循坏 return false
5.不然的话 就把数字插入set中
*/
#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int result) {
        std::unordered_set<int> nums_set;
        while (1) {
            result = getSum(result);
            if (result == 1) return true;
            else if (nums_set.find(result) != nums_set.end()) return false;
            else nums_set.insert(result);
       } 
    }
};
int main() {
    std::vector<int> vi;
}