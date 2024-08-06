class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0,m = num1.size(),n = num2.size();
        string ans;
        for (int i = m - 1,j = n - 1;i >= 0 || j >= 0;i--,j--) {
            int a = i >= 0?num1[i] - '0':0;
            int b = j >= 0?num2[j] - '0':0;
            int sum = a + b + carry;
            if (sum > 9) {
                carry = 1;
                sum %= 10;
            }else carry = 0;
            ans += to_string(sum);
        }
        if (carry == 1) ans += "1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
