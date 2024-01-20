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
#include <iostream>
#include <vector>

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
void print(const std::vector<int>& vi);
int main() {
    //std::vector<int> array{1,2,4,6,7};
    std::vector<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(4);
    array.push_back(6);
    array.push_back(7);
    print(array);
    std::cout << "find index = " << binarySearch(array,7) << std::endl;
}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
