
/*
        /冒泡排序
交换排序
        \快速排序
最坏时间复杂度：O(n^2)
稳定算法
适用于顺序表 链表
*/

#include <iostream>
#include <vector>
void bubbleSort(std::vector<int>& vi) {
    for (int i = 0;i < vi.size()-1;i++) {   //处理vi.size()-1个元素
        bool flag = false;
        for (int j = 0;j < vi.size()-i-1;j++) {     //第一个for循环处理完成之后都会确定一个最大的元素 所以j < vi.size()-i 因为满足条件要std::swap(vi[j],vi[j+1]) 保证数组不越界 j < vi.size()-i-1 
            if (vi[j] > vi[j+1]) {          //不应该是if (vi[j] >= vi[j+1]) 这样可以保证算法的稳定
                std::swap(vi[j],vi[j+1]);
                flag = true;
            }   
        }
        if (flag == false) return;
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
    bubbleSort(array);
    std::cout << "bubble sort:" << std::endl;
    print(array);
}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}