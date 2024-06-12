class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> ans;        
        ans = merge(meetings);
        int sum = 0;
        for (auto& vi:ans) {
            sum += vi[1] - vi[0] + 1;
        }
        return days - sum;
    }
    //参考LC.52.merge
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //对左端点进行排序
        std::sort(intervals.begin(),intervals.end(),
            [](const vector<int>& a,const vector<int>& b) { //使用了lambda表达式
                return a[0] < b[0];
            }
        );
        vector<vector<int>> ans;
        for (auto& vi:intervals) {
            //当前ans不为空并且 当前遍历区间的左端点 <= ans最后一个区间的右端点
            /*
            q1:为什么要添加条件!ans.empty()
            a1:因为第一次进入loop时 需要把intervals第一个元素push进ans 也就是执行else 这样才能进行后续的对比
            */
            if (!ans.empty() && vi[0] <= ans.back()[1]) {   //可以继续合并区间 大区间包括或等于小区间
                /*
                q2:为什么要取max(ans.back()[1],vi[1]);
                a2:因为直接取 我们不知道vi[1]和ans.back()[1]哪个大 可能ans为[1,10] 而vi为[2,9]
                */
                ans.back()[1] = max(ans.back()[1],vi[1]);
            }else {
                ans.emplace_back(vi);
            }
        }
        return ans;
    }
};
