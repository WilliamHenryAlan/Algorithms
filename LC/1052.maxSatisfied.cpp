
/*
分解问题
    1.不生气所有能满意的顾客

    2.连续k个minates内可以令最多原本不满意的顾客满意

1.直接累加所有grumpy[i] == 0的sum

2.滑动窗口模版 长度为k的范围内grumpy[i] == 1最大顾客总和
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size(),sum = 0,ans = 0;
        for (int i = 0;i < n;i++) if (grumpy[i] == 0) sum += customers[i];
        for (int i = 0;i < n;++i) {
            if (grumpy[i] == 1) sum += customers[i];
            if (i < k - 1) continue;
            ans = max(ans,sum);
            if (grumpy[i - k + 1] == 1) sum -= customers[i - k + 1];
        }
        return ans;
    }
};
