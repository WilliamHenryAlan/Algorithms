/*

        /简单选择排序
选择排序
        \堆排序

分为大根堆（大顶堆）和小根堆（小顶堆）
堆排序为不稳定算法
*/

#include <iostream>
#include <vector>
#include <chrono>
//adjust以nums[i]为root的子树 使他的左右孩子小于他 如果有左右孩子的话
void HeadAdjust(std::vector<int>& nums,int k) {
    nums[0] = nums[k];   //nums[0]可以暂存需要处理node的value
    int len = nums.size();
    for (int i = k*2;i <= len;i*=2) {
        if (i < len && nums[i] < nums[i+1]) {
            i++;        //取key较大的child node下标
        }
        if (nums[0] >= nums[i]) {   //complete adjustment
            break;      
        }else { 
            nums[k] = nums[i];      //将nums[i]调整到parents node上
            k = i;                  //修改k值 方便下次adjustment
        }
    }
    nums[k] = nums[0];              //被筛选结点放入最终位置
}
void buildMaxHeap(std::vector<int>& nums) {
    int len = nums.size();
    for (int i = len/2;i > 0;--i) { //index 0 不存储element len/2往前的node为branch node
        HeadAdjust(nums,i);         //处理每一个branch node
    }
}

void heapSort() {
    
}
void print(const std::vector<int>& vi);
int main() {
    //Create test object
    std::vector<int> array;
    array.push_back(-1);
    array.push_back(53);
    array.push_back(17);
    array.push_back(78);
    array.push_back(9);
    array.push_back(45);
    array.push_back(65);
    array.push_back(87);
    array.push_back(32);

    //for (int i = 100;i >= 0;i--) array.emplace_back(i);
    print(array);

    auto start = std::chrono::high_resolution_clock::now();     //测试程序运行时间begin
    //###############################################################################
    buildMaxHeap(array);
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
