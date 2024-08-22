


XOR为异或操作：

一个数和 0 做异或 等于本身： num ⊕ 0 = num 

一个数和自己做异或 等于 0： num ⊕ num = 0 

异或满足交换律和结合律

遍历数组中的每一个num 进行异或 因为 除了某个元素只出现一次以外 其余每个元素均出现两次 所以最后剩下的那个就是我们要求的




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int num : nums)  // 1. 遍历 nums 执行异或运算
            x ^= num;
        return x;            // 2. 返回出现一次的数字 x
    }
};
