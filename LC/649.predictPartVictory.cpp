class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad,dir;
        int n = senate.size();
        for (int i = 0;i < n;i++)
            if (senate[i] == 'D') dir.push(i);
            else rad.push(i);
        while (rad.size() != 0 && dir.size() != 0) {
            int a = rad.front();
            int b = dir.front();
            rad.pop();
            dir.pop();
            if (a < b) rad.push(a + n);
            else dir.push(b + n);
        }
        return rad.size() == 0?"Dire":"Radiant";
    }
};
