class Solution {
public:
    int countDigits(int num) {
        int temp = num,digit,ans = 0;
        while (temp) {
            if (num % (temp % 10) == 0) ans++;
            temp /= 10;
        }
        return ans;
    }
};