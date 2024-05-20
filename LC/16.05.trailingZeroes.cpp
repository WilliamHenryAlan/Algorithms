#include <iostream>
using namespace std;

//failure   数学问题
class Solution {
public:
    void traverse(int n,long long& ret) {
        if (n == 1 || n == 0) {
            return ;
        }
        ret *= n;
        traverse(--n,ret);
    }
    int trailingZeroes(int n) {
        long long ret = 1;
        int count = 0;
        traverse(n,ret);
        while (ret%10 == 0) {
            count++;
            ret /= 10;
        }
        return count;
    }
};