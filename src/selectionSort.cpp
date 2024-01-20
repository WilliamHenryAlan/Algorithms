/*
        /简单选择排序
选择排序    
        \堆排序

算法思想：
升序为例 循环遍历整个表 每次选取最小值分别插入到第一个 第二个 第三个 以此类推
遇到相同的先处理先遇到的 保证稳定性
最后一个元素无需变动 进行n-1次处理
*/


#include <iostream>
#include <vector>
void selectionSort(std::vector<int>& vi) {
    for (int i = 0;i < vi.size()-1;i++) {       //遍历整个表除了最后一个元素
        int min = i;                            //暂存最小元素下标
        for (int j = i+1;j < vi.size();j++) {   //遍历剩下元素 对比如果有元素小于最小元素 则把其下标赋值给min
            if (vi[min] > vi[j]) {
                min = j;
            }
        }
        if (min != i) {                 //如果有改动 交换两个元素
            std::swap(vi[min],vi[i]);
        }
    }
}
void print(const std::vector<int>& vi);
int main() {
    std::vector<int> array;
    array.push_back(49);
    array.push_back(38);
    array.push_back(65);
    array.push_back(97);
    array.push_back(76);
    array.push_back(13);
    array.push_back(27);
    array.push_back(49);
    print(array);
    selectionSort(array);
    std::cout << "selection sort:" << std::endl;
    print(array);
}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

/*
算法不稳定

算法的时间复杂度不会因为给的初始序列的不同变化 都是O(n^2)
比如插入排序 如果一开始给出的元素基本有序 则可以达到O(n)
*/