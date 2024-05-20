/*
2023.12.21
issue:return前k个高频元素的集合
solution：
想到hashtable key为字符 value为次数
先遍历vector 然后基于value做一个quicksort 时间复杂度为O(nlog(n))

其实没必要排序所有的元素 只需要维护前k个有序集合即可
大顶堆和小顶堆很适合在一个很庞大的集合里找高频或者低频的元素 底层实现就是compelte二叉树

*/

/*

note:
1.优先队列包含在<queue>头文件中 由大顶堆或者小顶堆实现 大顶堆或者小顶堆的底层实现逻辑为完全二叉树
2.for (int i = nums.size()-1;i >= 0;i--) {

}降序遍历代码的条件要看仔细


*/
#include <iostream>
#include <vector>
#include <map>
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int,int> myMap;
        for (const int& i:nums) {   //对vector中的元素进行记录key为数字 value为出现次数
            myMap[i]++;             
        }

    }
};


/*
note:
1.      for (int& elem:nums) {
            hashTable[elem]++;
        }
        这样写
        和这样
        for (int& elem:nums) {
            if (hashTable.find(elem) == hashTable.end()) {
                hashTable.emplace(elem,1);
            }else {
                hashTable[elem]++;
            }
        }
效果是一样的 都是对vector中的元素进行记录key为数字 value为次数
            
2.如何自定义比较函数
*/
#include <iostream>
#include <vector>
#include <unordered_map>
class Solution {
public:
    static bool compare(const std::pair<int,int>& pair1, const std::pair<int,int>& pair2) {
        return pair1.second > pair2.second;
    }
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> hashTable;
        for (int& elem:nums) {
            hashTable[elem]++;
        }
        std::vector<std::pair<int,int>> pairs(hashTable.begin(),hashTable.end());
        std::sort(pairs.begin(),pairs.end(),compare);
        std::vector<int> ret;
        for (int i = 0;i < k;i++) {
            ret.push_back(pairs[i].first);
        }
        return ret;
    }
};