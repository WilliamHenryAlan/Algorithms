/*
算法思想：
遍历整个表 分为已排序和未排序 从index = 1的元素开始对比前一个元素
升序为例 如果前一个元素大于当前元素 则继续向前比较 直到对比到小于等于当前元素的值 
把不包括当前值 之后的所有元素后移一位
*/

#include <iostream>
#include <vector>
void insertSort(std::vector<int>& vi) {
    for (int i = 1;i < vi.size();i++) {
        if (vi[i-1] > vi[i]) {
            int temp = vi[i];
            int j;
            for (j = i-1;j >= 0;j--) {
                vi[j+1] = vi[j];
                if (vi[j] <= temp) {
                    break;
                }
            }
            vi[j+1] = temp;
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


/*
稳定算法

优化思路：
对比元素时 因为前面的元素已经有序了 可以使用二分查找
*/