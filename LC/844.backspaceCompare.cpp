#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for (char val:s) {
            if (!a.empty() && val == '#') a.pop();
            else if (a.empty() && val == '#') continue;
            else a.push(val);
        }
        for (char val:t) {
            if (!b.empty() && val == '#') b.pop();
            else if (b.empty() && val == '#') continue;
            else b.push(val);
        }
        if (a == b) return true;
        return false;
    }
};
