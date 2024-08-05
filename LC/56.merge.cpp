class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b) {return a[0] < b[0];});
        vector<vector<int>> ans;
        for (vector<int>& vi:intervals) {
            if (!ans.empty() && vi[0] <= ans.back()[1]) 
                ans.back()[1] = max(vi[1],ans.back()[1]);
            else ans.push_back(vi);
        }
        return ans;
     }
};
