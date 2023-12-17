/*
23.12.17
solution：
因为是寻找匹配元素 寻找 target - 每一个元素的另一元素
所以想到hashtable 并且要return下标 所以要用std::unordered_map 底层用哈希表实现 无序 不可以重复

1.把vector映射到map中
2.遍历整个vector 在map中找是否存在匹配值
3.如果找到了就return
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> nums_map;
        int len = nums.size();
        for (int i = 0;i < len;i++) {
            auto iter = nums_map.find(target-nums[i]);
            if (iter == nums_map.end()) {
                nums_map.insert(std::pair<int,int>(nums[i],i));
            }else {
                return {i,iter->second};
            }
        }
        return {};
    }
};