class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0;i < n;i++) {
            int spare = gas[i];
            for (int j = i;spare - cost[j] >= 0;) {
                spare = spare - cost[j] + gas[(j + 1) % n];
                j = (j + 1) % n;
                if (j == i) return i;
            }
        }
        return -1;
    }
};

/*
1.算出每个站点的消耗+补给

2.走不完的情况因为消耗>补给

3.  ans = 0 从0开始跑  sum = 0  累加 如果出现负数 说明当前 ans 开始跑是不能满足的
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentSum = 0,sum = 0,ans = 0,n = gas.size();
        for (int i = 0;i < n;++i) {
            //算出每个站点的消耗+补给
            int x = gas[i] - cost[i]; 
            sum += x;
            currentSum += x;
            //ans = 0 从0开始跑  sum = 0  累加 如果出现负数 说明当前 ans 开始跑是不能满足的
            if (currentSum < 0) {
                ans = i + 1;
                currentSum = 0;
            }
        }
        return sum < 0?-1:ans;
    }
};