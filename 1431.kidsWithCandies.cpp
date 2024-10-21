class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = candies[0],n = candies.size();
        for (int& val:candies) if (val > max) max = val;
        vector<bool> ret;
        for (int& val:candies) 
            if (val + extraCandies >= max) ret.push_back(true);
            else ret.push_back(false);
        return ret;
    }
};
