/*
23.12.17
solution：
因为是寻找匹配元素 寻找 target - 每一个元素的另一元素
所以想到hashtable 并且要return下标 所以要用std::unordered_map 底层用哈希表实现 无序 不可以重复

1.创建一个empty map
2.遍历整个vector 在map中找是否存在匹配值：
                                    如果不匹配 就把元素插入到map中
                                    如果匹配 就return
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
                return {i,iter->second};    //implicit 可以写成explicit return std::vector<int>{iter->second,i};
            }
        }
        return {};
    }
};
/*
summary：
1.c++的哈希表用了动态数组的方式和哈希函数组成
2.插入可以用pair函数 也可以写成 nums_map.insert({nums[i],i}); 用初始化列表的方式
*/