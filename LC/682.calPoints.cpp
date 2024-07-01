#include <iostream>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (string& ops:operations) {
            if (ops == "C") st.pop();
            else if (ops == "D") {
                int temp = st.top();
                st.push(temp * 2);
            }
            else if (ops == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            }else st.push(stoi(ops));
        }
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }   
};