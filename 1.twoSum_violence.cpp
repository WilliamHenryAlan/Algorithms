/*
23.12.17
1.暴力两个for循环 第一个loop遍历每一个元素
2.因为一个位置的两个元素不能重复使用 所以第二个loop从i+1开始遍历整个vector

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
        for (int i = 0;i < nums.size();i++) {
            for (int j = i+1;j < nums.size();j++) {
                if (nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

int main()
{
    std::vector<int> vi;
    vi.push_back(2);
    vi.push_back(7);
    vi.push_back(11);
    vi.push_back(15);
    vi=twoSum(vi,9);
    for (int i:vi)
    {
        std::cout << i << " ";
    }
}