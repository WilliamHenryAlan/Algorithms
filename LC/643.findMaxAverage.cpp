/*
1.注意设置ans为min 因为答案可能出现negative

2.第一个if进入窗口 第一个if和第二个if会完成初始化窗口的任务 此时窗口增加元素 会循环执行for循环的第一二条

3.第一个if完成后将不会再进入 此时更新答案 

自此 之后的loop将周而复始执行
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN,sum = 0;
        for (int i = 0;i < nums.size();i++) {
            sum += nums[i];
            if (i < k - 1) continue;
            //数据正常情况下 上两个个if会完成初始化窗口的任务 此时更新答案 下一个if开始开始循环
            ans = max(ans,sum/k);
            sum -= nums[i - k + 1];
        }
        return ans;
    }
};