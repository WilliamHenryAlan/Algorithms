/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
*/

/*
solution:
1.看到这种（给定一个元素 判断在这个集合里是否出现过）这样的问题 就想到hash table
                                                            1.vector 数值不是很大的时候 比如这道题 有限制<1000
                                                            2.set 数值比较分散 
                                                            3.map
2.除去限制条件 选择数组太大 而且浪费空间 所以选择set中的unordered_set 去重 而且效率高
3.先创建一个unordered_set nums_set 传入num1的begin和end迭代器 把nums1进行映射
4.循环遍历nums2的元素 如果找到就把元素插入到unordered_set ret里
5.最后把ret这个集合转化为数组返回
*/
#include <iostream>
#include <unordered_set>
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> ret;
        std::unordered_set<int> nums_set(nums1.begin(),nums1.end());//3.
        for (int element:nums2) {                           //4.
            if (nums_set.find(element) != nums_set.end()) {     //nums_set.find(element)返回一个迭代器 如果没找到返回end()
                ret.insert(element);
            }
        }
        return std::vector<int>(ret.begin(),ret.end());
    }
};
