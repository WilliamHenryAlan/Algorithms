//因为通过反转所得 拼接两个s则必然包含goal
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).contains(goal);
    }
};
//拼接+还原
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.size();
        for (int i = 0;i < n;i++) {
            if (goal[i] == s[0]) {
                string a = goal.substr(i,n - i);
                string b = goal.substr(0,i);
                if (a + b == s) return true;
            }
        }
        return false;
    }
};

