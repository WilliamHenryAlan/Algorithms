/*
建立left和right数组 所有的孩子都先分发一个糖果 遍历两次ratings
1. left[i] 表示遵循 右侧的孩子如果比左侧孩子评分高 那么右侧的孩子比左侧的孩子糖果多一个
2. right[i] 从后往前遍历 表示遵循 左侧的孩子如果比右侧孩子评分高 那么左侧侧的孩子比右侧的孩子糖果多一个
3.遍历left和right 取max
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n,1),right(n,1);
        for (int i = 1;i < n;++i) {
            if (ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
        }
        int ans = left[n - 1];
        for (int i = n - 2;i >= 0;--i) {
            if (ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
            ans += max(left[i],right[i]);
        }
        return ans;
    }
};
