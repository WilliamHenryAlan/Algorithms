/*
二分思想
二分思想的本质是二段性 二分查找为其中的一种用法

时间复杂度：n个数 n, n/2, n/4, n/8...n/2^k => O(logN)
局限性：1.需要有序 但是无序情况下也可以用二分找区间
       2.需要能够随机访问 链式存储没可以用跳表
*/
#include <iostream>
#include <vector>
using namespace std;

//找到 >= target的最小值
int lower_bound1(const vector<int>& nums,int target);
//找到 >= target的最小值
int lower_bound2(const std::vector<int>& nums, int target);
//找 > target的最小值
int upper_bound1(const std::vector<int>& nums,int target);
int upper_bound2(const std::vector<int>& nums,int target);
int binarySearch(const std::vector<int>& vi,const int& target);
void print(const std::vector<int>& vi);

int main() {
    std::vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(2);
    array.push_back(2);
    array.push_back(4);
    array.push_back(4);
    array.push_back(6);
    array.push_back(7);
    print(array);
    cout << "func lower_bound() = " << distance(array.begin(),lower_bound(array.begin(),array.end(),3)) << endl;
    cout << "func lower_bound() = " << lower_bound2(array,3) << endl;
    cout << "func lower_bound() = " << distance(array.begin(),upper_bound(array.begin(),array.end(),5)) << endl;
    cout << "func lower_bound() = " << upper_bound1(array,5) << endl;

}
/*
    我们不关心区间内数组的情况 而是可以确定区间外数组的情况
*/
int lower_bound1(const vector<int>& nums,int target) {    
    int l = 0,r = nums.size();//左闭右闭区间   循环条件要写为l <= r因为l = r的时候是有意义的
    while (l <= r) { //循环结束之后 r一定在l的左边
        int m = l + (r - l) / 2;//防止溢出
        if (nums[m] < target) l = m + 1;//l左边的数组严格小于target
        else r = m - 1; //右边的数组严格大于等于target
    }
    return l;   //r + 1
}
//找到 >= target的最小值
int lower_bound2(const std::vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int len = nums.size();
    int l = 0,r = len;  //左闭右开区间
    while (l < r) {     //循环退出的时候left = right
        int mid = l + (r - l) / 2;  //防止溢出
        if (nums[mid] >= target) {  //说明[mid,right)严格大于等于target
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    return r;
}
//找 > target的最小值
int upper_bound1(const std::vector<int>& nums,int target) {
    if (nums.size() == 0) return -1;
    int len = nums.size();
    int l = 0,r = len - 1;//[]
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) {
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    return r;
}
int upper_bound2(const std::vector<int>& nums,int target) {
    if (nums.size() == 0) return -1;
    int len = nums.size();
    int l = 0,r = len;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= target) {
            l = mid + 1;
        }else {
            r = mid;
        }
    }
    return r;
}
int binarySearch(const std::vector<int>& vi,const int& target) {
    int low = 0;
    int high = vi.size()-1;
    int mid = 0;
    while (low <= high) {
        mid = (low+high)/2;
        if (vi[mid] == target) {
            return mid;
        }else if (vi[mid] > target) {
            high = mid-1;
        }else {
            low = mid+1;
        }
    }
    return -1;
}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


/*
二分查找也叫折半查找 O(logn)
前提是必须是有序序列

solution:
以升序为例
双指针 low high 分别指向头尾的index
遍历整个array 每次求middle index = (low+high)/2
对比target和array[mid]: 会出现三种情况
if (array[mid] > target)  mid的值比目标大 升序序列 说明目标在左边   移动high = mid-1
if (array[mid] < target)  mid的值比目标小 升序序列 说明目标在右边   移动low = mid+1
if (array[mid] == target) 找到target    return mid    

迭代array的条件为low <= heigh
选取边界条件 当low == heigh 时 应该继续循环 这样才能判定是否存在target

target = 2
arr:    1   2   4   6   7
        ^       ^       ^
        low     mid    high
arr:    1   2   4   6   7
        ^   ^   ^       
        l   h   m 
arr:    1   2   4   6   7
        ^   ^          
        l   h   
        ^
        m
arr:    1   2   4   6   7
        ^   ^          
        l   h   
        ^
        m
arr:    1   2   4   6   7
            ^          
            h   
            ^
            l
边界情况low == heigh 应该继续 mid = 1 array[1] == target return 1
        
*/

