/*
二分思想
二分思想的本质是二段性 二分查找为其中的一种用法

时间复杂度：n个数 n, n/2, n/4, n/8...n/2^k => O(logN)
局限性：1.需要有序 但是无序情况下也可以用二分找区间
       2.需要能够随机访问 链式存储没可以用跳表

我们不关心区间内数组的情况 而是可以确定区间外数组的情况

>= x 用lower_bound解决
> >=x+1
< (>=x) - 1
<= (>x) - 1

*/
#include <iostream>
#include <vector>
using namespace std;

void buildArr(std::vector<int>& vi);
int lower_bound1(const vector<int>& nums,int target);
//找到 >= target的最小值
int lower_bound2(const std::vector<int>& nums, int target);
//找 > target的最小值
int upper_bound1(const std::vector<int>& nums,int target);
int upper_bound2(const std::vector<int>& nums,int target);
int binarySearch(const std::vector<int>& vi,const int& target);
void print(const std::vector<int>& vi);

int main() {
    std::vector<int> array;buildArr(array);print(array);
    cout << "std::lower_bound = " << distance(array.begin(),lower_bound(array.begin(),array.end(),3)) << endl;
    cout << "func lower_bound1 = " << lower_bound1(array,3) << endl;
    cout << "std::upper_bound = " << distance(array.begin(),upper_bound(array.begin(),array.end(),5)) << endl;
    cout << "func lower_bound2 = " << lower_bound2(array,6) << endl; //lower_bound <=> upper_bound
}


//[]
int lower_bound1(const vector<int>& nums,int target) {    
    int l = 0,r = nums.size();// 循环条件要写为l <= r因为l = r的时候是有意义的
    while (l <= r) { //循环结束之后 r一定在l的左边
        int m = l + (r - l) / 2;//防止溢出
        if (nums[m] < target) l = m + 1;//R + 1的区域 >= target
        else r = m - 1; //L - 1的区域 < target
    }
    return l;   //r + 1
}
 //[)
int lower_bound2(const std::vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int len = nums.size();
    int l = 0,r = len;
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
void buildArr(std::vector<int>& vi) {
    array.push_back(1);
    array.push_back(2);
    array.push_back(4);
    array.push_back(6);
    array.push_back(7);
    array.push_back(2);
    array.push_back(2);
    array.push_back(4);
    array.push_back(4);
    array.push_back(6);
    array.push_back(7);
}
    