#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
review 2024.6.29
*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for (char ch:s) {
            if (!a.empty() && ch == '#') a.pop();
            else if (ch != '#') a.push(ch);
        }
        for (char ch:t) {
            if (!b.empty() && ch == '#') b.pop();
            else if (ch != '#') b.push(ch);
        }
        return a == b;
    }
};
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
