none


/*
算法思想：
对插入排序进行优化 用二分查找
注意细节：1.折半查找的循环终止条件如何设置可以保证算法的稳定性
        2.折半查找完成后元素的插入位置
*/

#include <iostream>
#include <vector>
void insertSort(std::vector<int>& vi) {

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
    insertSort(array);
    std::cout << "insert sort:" << std::endl;
    print(array);
}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
