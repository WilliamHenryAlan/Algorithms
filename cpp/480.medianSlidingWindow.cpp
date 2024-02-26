#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
1.直接想法每次滑动窗口 求出中位数
    nums有序的情况下
    奇数：mid指向中间的数字 偶数：mid指向中间两个数的后面那个数字
    所以 如果这样写 middle_value = (nums[mid] + nums[mid - 1 + k % 2]) / 2
    将可以不用探讨奇偶性
    如果是奇数：k % 2 = 1
    (nums[mid] + nums[mid]) / 2
    如果是偶数：k % 2 = 0
    (nums[mid] + nums[mid - 1]) / 2
2.如果每次滑动窗口都进行排序+找中位数 时间复杂度为O（n) * (O(k) + O(klog(k)))会超时
3.考虑用红黑树维护滑动窗口 c++中对应multiset 因为不用存储kv
4.但是上述公式寻找mid只能对于有随机存储的容器
5.对于链式存储 仍然需要O(n)时间复杂度找到中间的node（类似linkedList中求中间node fast走两步 slow走一步）
6.如果要用红黑树 只能使用移动next和prev来降低时间复杂度 使得不用每次O(n)寻找mid
*/

//左闭右闭常规写法
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> hash(nums.begin(),nums.begin() + k);//预处理第一次滑动窗口
        int len = nums.size();
        int l = 0;
        int r = k - 1;
        //第一次设置mid O(n) 也可以用std::advance
        auto mid = next(hash.begin(),k / 2);  
        vector<double> ans;
        while (r < len) {
            //每次开始 都是已经设置好了mid 第一次已经预处理 所以开始直接获取中位数
            //不用考虑奇偶性 只是换成了迭代器
            double middle_value = ((double)(*mid) + (double)*prev(mid, 1 - k % 2)) / 2;
            ans.push_back(middle_value);
            if (r + 1 == len) break;
            //先插入再移动 再移动 再删除
            hash.insert(nums[++r]);
            if (nums[r] < *mid) mid--;
            if (nums[l] <= *mid) mid++;
            hash.erase(hash.find(nums[l++]));
        }
        return ans;
    }
};

//左闭右开写法
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        multiset<int> window(nums.begin(), nums.begin() + k);
        //设置第一次滑动窗口时的mid
        auto mid = std::next(window.begin(), k / 2);
        for (int idx = k; ; idx++) {
            //通用公式 不需要分类讨论奇偶性 计算中位数
            auto midValue = ((double)(*mid) + 
                            (double)*prev(mid, 1 - k % 2)) / 2;
            ret.push_back(midValue);
            //左闭右开区间
            if (idx == nums.size()) break;
            // 先加入新元素 再移动指针
            window.insert(nums[idx]);
            if (nums[idx] < *mid)   //如果新加入的元素比当前小 mid = prev(mid)
                mid--;
            //先判断要删除的元素是否 <= *mid 如果先删除 将会产生悬挂指针
            if (nums[idx - k] <= *mid)
                mid++;
            // 删除元素
            window.erase(window.find(nums[idx-k]));
        }
        return ret;
    }
};
