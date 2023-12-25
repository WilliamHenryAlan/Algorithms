/**
 * 归并排序思想：
 * 核心思想为：把数组中两个有序的序列进行归并
 * 1.拆分子表
 * 2.归并子表
 * 
 * 归并排序实际上就是后序遍历
 * 
 * 时间复杂度O(nlog(n))   
 * 根据两路归并树推出 无论是逆序还是其他 时间复杂度不变 对比quickSort 快排最坏可能达到O(n^2)
 * 
 * 空间复杂度O(n) 主要来自辅助数组 tempNums
 * 稳定算法
*/
#include <iostream>
#include <vector>
#include <chrono>
void merge(std::vector<int>& nums,int low,int mid,int high) {
    std::vector<int> tempNums(nums.size(),0);   //分配和nums一样大的数组空间
    for (int i = low;i <= high;i++) {   //把需要归并的子数组copy到temporary
        tempNums[i] = nums[i];
    }
    int i = low,j = mid+1,k = low;      //i和j分别指向需要归并到两个子数组 k指向归并完成的nums
    while (i <= mid && j <= high) {     //当有一个子数merge完成 loop结束
        if (tempNums[i] <= tempNums[j]) {   //对比*i和*j 比较小的放入*k     //这里取等号保证算法的稳定性
            nums[k] = tempNums[i++];    
        }else {
            nums[k] = tempNums[j++];
        }
        k++;
    }
    while (i <= mid) nums[k++] = tempNums[i++];
    while (j <= high) nums[k++] = tempNums[j++];
}
void mergeSort(std::vector<int>& nums,int low,int high) {
    if (low <high) {
        int mid = (low+high)/2;     //从中间划分
        mergeSort(nums,low,mid);    //对左子表进行归并
        mergeSort(nums,mid+1,high); //对右子表进行归并
        merge(nums,low,mid,high);   //总归并
    }
}
void print(const std::vector<int>& vi);
int main() {
    //Create test object
    std::vector<int> array;
    array.push_back(49);
    array.push_back(38);
    array.push_back(65);
    array.push_back(97);
    array.push_back(76);
    array.push_back(13);
    array.push_back(27);
    array.push_back(49);
    array.push_back(23);
    array.push_back(32);
    array.push_back(3213);
    array.push_back(321);
    array.push_back(-2313);
    array.push_back(-100);
    array.push_back(34);
    array.push_back(99);
    array.push_back(39);
    array.push_back(29);
    array.push_back(19);
    for (int i = 100;i >= 0;i--) array.emplace_back(i);
    print(array);

    auto start = std::chrono::high_resolution_clock::now();     //测试程序运行时间begin
    //###############################################################################
    mergeSort(array,0,array.size()-1);
    //###############################################################################
    auto stop = std::chrono::high_resolution_clock::now();      //测试程序运行时间end
    //Print result
    std::cout << "程序运行时间：" << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " 微秒" << std::endl;
    std::cout << "quick sort:" << std::endl;
    print(array);
}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}