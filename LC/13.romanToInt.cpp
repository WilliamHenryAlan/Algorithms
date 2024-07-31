class Solution {
public:
    int romanToInt(string s) {
        int sum = 0,pre = getValue(s[0]),n = s.size();
        for (int i = 1;i < n;i++) {
            int next = getValue(s[i]);
            if (next <= pre) {
                sum += pre;
            }else {
                sum -= pre;
            }
            pre = next;
        }
        sum += pre;
        return sum;
    }
    int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};

