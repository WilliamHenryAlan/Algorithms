#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());//因为是子序列不是子数组 顺序无所谓 可以先排序
        vector<int> prefixSum(n + 1,0);
        for (int i = 1;i <= n;i++) { //构建前缀和数组
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        vector<int> ans(queries.size(),0);
        for (int i = 0;i < ans.size();i++) {
            // for (int j = prefixSum.size() - 1;j >= 0;j--) {
            //     if (queries[i] >= prefixSum[j]) {
            //         ans[i] = j;
            //         break;
            //     }
            // }   
            //二分查找优化
            ans[i] = upper_bound(prefixSum.begin(),prefixSum.end(),queries[i]) - prefixSum.begin() - 1;
        }
        return ans;
    }
};
