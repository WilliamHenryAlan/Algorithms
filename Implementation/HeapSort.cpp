/*

        /简单选择排序
选择排序
        \堆排序

分为大根堆（大顶堆）和小根堆（小顶堆）
堆排序为不稳定算法
*/

#include <iostream>
#include <vector>
void HeadAdjust(std::vector<int>& nums,int k);
void buildMaxHeap(std::vector<int>& nums);
void heapSort(std::vector<int>& nums);
void print(const std::vector<int>& vi);
void buildArray(std::vector<int>& nums);

int main() {
    //Create test object
    std::vector<int> array; buildArray(array);
    //###############################################################################
    buildMaxHeap(array);
    heapSort(array);
    //###############################################################################
    //Print result
    std::cout << "heap sort:" << std::endl;
    print(array);
}

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

void heapSort(std::vector<int>& nums) {
    
}
void buildArray(std::vector<int>& nums) {
    nums.push_back(49);
    nums.push_back(38);
    nums.push_back(76);
    nums.push_back(13);
    nums.push_back(27);
    nums.push_back(49);
    nums.push_back(23);
    nums.push_back(32);
    nums.push_back(3213);
    nums.push_back(321);
    nums.push_back(-2313);
    nums.push_back(-100);
    nums.push_back(34);
    nums.push_back(99);
    nums.push_back(39);
    nums.push_back(29);
    nums.push_back(19);
    std::cout << "Array created successfully" << std::endl;
    print(nums);
}

void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
