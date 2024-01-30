#include <iostream>
#include <vector>
using namespace std;
/*
Method : greedy
1.题目要求只返回长度就可以 所以没必要删除数组元素 只需要计数就可以
2.计数分三种情况：
            峰顶/峰谷 - 前 => prevdiff => nums[i] - nums[i-1]
            峰顶/峰谷 - 后 => diff => nums[i] - nums[i+1]
            1.如果是    /\      prevdiff > 0 && diff > 0
            2.如果是    \/      prevdiff < 0 && diff < 0
            3.考虑到平坡的情况\--/ 或者/--\ 条件更改为  prevdiff < 0 && diff <= 0 || prevdiff > 0 && diff => 0
            4.考虑到    /--/或者\--\ 所以
            5.边界情况nums.size() <= 2 return nums.size()
            
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int diff = 0;
        int prevdiff = 0;
        int ans = 1;
        for (int i = 0;i < n-1;i++) {
            diff = nums[i+1] - nums[i];
            if (prevdiff <= 0 && diff > 0 || prevdiff >= 0 && diff < 0) {
                ans++;
                prevdiff = diff;
            }
        }
        return ans;
    }
};