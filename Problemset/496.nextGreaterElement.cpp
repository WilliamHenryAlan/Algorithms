#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
//Method 1:brute force

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(),-1);
        for (int i = 0;i < nums1.size();i++) {
            int k = 0;
            for (int j = 0;j < nums2.size();j++) {
                if (nums1[i] == nums2[j]) {
                    k = j;
                    break;
                }
            }
            for (;k < nums2.size();k++) {
                if (nums2[k] > nums1[i]) {
                    res[i] = k;
                    break; 
                }
            }
        }
        return res;
    }
};

//Method 2:hash+monotone stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int,int> hashmap;
        std::stack<int> st;
        int len = nums2.size();
        std::vector<int> res(len,0);
        for (int i = 0;i < len;i++) {
            while (st.size() > 0 and nums2[i] > st.top()) {
                hashmap[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for (int &i:nums1) {
            if (hashmap.find(i) != hashmap.end()) {
                i = hashmap[i];
            }else {
                i = -1;
            }
        }
        return nums1;
    }
};
