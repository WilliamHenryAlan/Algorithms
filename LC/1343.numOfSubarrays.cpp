class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0;
        int ans = 0,sum = 0;
        for (;i < arr.size();i++) {
            sum += arr[i];
            if (i < k - 1) continue;
            if (sum / k >= threshold) ans++;
            sum -= arr[i - k + 1];
        }
        return ans;
    }
};