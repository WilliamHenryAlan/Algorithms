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
        std::unordered_map<int,int> hashtable;
        int len = nums.size();
        for (int i = 0;i < len;i++) {
            int temp = target-nums[i];
            if (hashtable.find(temp) != hashtable.end()) {
                return {hashtable[temp],i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};



/*
2023.12.17
brute force     O(n^2)
1.暴力两个for循环 第一个loop遍历n-1个元素
2.因为一个位置的两个元素不能重复使用 所以第二个loop从i+1开始遍历整个vector
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
        int len = nums.size();
        for (int i = 0;i < len-1;i++) {
            for (int j = i+1;j < len;j++) {
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

/*
summary：
1.c++的哈希表用了动态数组的方式和哈希函数组成
2.插入可以用pair函数 也可以写成 nums_map.insert({nums[i],i}); 用初始化列表的方式
*/