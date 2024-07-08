/*
1.边界条件处理 

    1.半径大于数组长度 vector值全是-1

    2.k = 0 半径长度为0 return nums

2.滑动窗口求和sum为long long 不然会爆int

3.滑动窗口处理逻辑：

    窗口为[0,i]左闭右闭

    1.循环进入后 先循环执行第一个if和第二个if 直到固定窗口

    2.固定窗口大小后 更新答案 执行第三个if 离开窗口

    3.执行第1个if 进入窗口 此后 第二个if将不会进入

*/
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if (k == 0) return nums;
        if (n < k) return ans;
        long long sum = 0,kk = 2 * k;
        for (int i = 0;i < n;i++) {
            sum += nums[i];
            if (i < kk) continue;
            ans[i - k] = sum / (kk + 1);
            sum -= nums[i - kk];
        }
        return ans;
    }
};
