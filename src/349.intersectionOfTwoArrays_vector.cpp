#include <iostream>
#include <unordered_set>
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> ret;
        int hash[1001]{0};
        for (int element:nums1) {
            hash[element] = 1;
        }
        for (int element:nums2) {
            if (hash[element] == 1) {
                ret.insert(element);
            }
        }
        return std::vector<int>(ret.begin(),ret.end());
    }
};
int main() {

}
// class Solution {
// public:
//     std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
//         std::vector<int> n1(1000,0);
//         std::vector<int> n2(1000,0);
//         std::vector<int> ret;
//         for (int i = 0;i < nums1.size();i++) {
//             n1[nums1[i]]++;
//         }

//         for (int i = 0;i < nums2.size();i++) {
//             n2[nums2[i]]++;
//         }
//         for (int i = 0;i < 1000;i++) {
//             if (n1[i] != 0 and n2[i] != 0) {
//                 ret.push_back(i);
//             }
//         }
//         return ret;
//     }
// };