/*
        /冒泡排序
交换排序
        \快速排序

快速排序思想：
1.从表中选取一个元素作为pivot(枢轴或者基准)
2.升序为例作划分 low和high指针指向头尾 把表划分为两个部分 枢轴左边的要比枢轴小 右边的要比枢轴大


initialization array:  49  38  65  97  76  13  27  49
开始第一次划分

1.int pivot = 49 保存枢轴元素 此时 pivot指向的位置是空出来的 所以要移动h指针
array:  empty  38  65  97  76  13  27  49
        ^l                              ^h

2.pivot = 49
array:  empty  38  65  97  76  13  27  49
        ^l                         ^h
因为arr[high] >= pivot high--

3.pivot = 49
array:  empty  38  65  97  76  13  27  49
        ^l                         ^h
因为27 < 49 所以要把 arr[low] = arr[high] low++

4.pivot = 49
array:  27  38  65  97  76  13  empty  49
            ^l                   ^h
此时high指针指向的位置是空的（虽然实际上不是空的）
此时high指针不动 移动low指针
38 < 49 low++

5.pivot = 49
array:  27  38  65  97  76  13  empty  49
                ^l               ^h
65 > 49 arr[high] = arr[low] high--

6.pivot = 49
array:  27  38  empty  97  76  13  65  49
                ^l             ^h
移动high指针
13 < 49 arr[low] = arr[high] low++

7.pivot = 49
array:  27  38  13  97  76  empty  65  49
                    ^l      ^h
此时移动low指针
97 > 49 arr[high] = arr[low] high--

8.pivot = 49
array:  27  38  13  empty  76  97  65  49
                    ^l     ^h
76 > 49 不交换 high--

9.pivot = 49
array:  27  38  13  empty  76  97  65  49
                    ^l
                    ^h
当low == high 时 已经遍历了整个表 
左边都是比49更小的元素 27  38  13
右边都是比49更大或者相等的元素 76  97  65  49

至此 就完成了一次划分的过程 确定了枢轴49的位置是放在index为3的地方
array:  27  38  13  49  76  97  65  49
index:  0   1   2   3   4   5   6   7

对左子表进行划分
left subArray:  27  38  13

1.pivot = 27
left subArray:  27(empty)  38  13
                ^l              ^h
13 < 27 交换arr[low] = arr[high] low++

2.pivot = 27
left subArray:  13  38  13(empty)
                    ^l  ^h
38 > 27 交换arr[high] = arr[low] high--

3.pivot = 27
left subArray:  13  38(empty)  38
                    ^l
                    ^h
low == high 划分结束 确定了27的位置
左右子表都只有一个元素 所以low == high 无需划分

当前array:  13  27  38  49  76  97  65  49

对右子表进行划分:
right subArray:   76  97  65  49

1.int pivot = 76
right subArray: 76(empty)  97  65  49
                ^l                 ^h
49 < 76 交换 low++

2.int pivot = 76
right subArray: 49  97  65  49(empty)
                    ^l      ^h
97 > 76 交换 high--

3.int pivot = 76
right subArray: 49  97(empty)  65  97
                    ^l          ^h
65 < 76 交换 low++

4.int pivot = 76
right subArray: 49  65  65  97
                        ^h
                        ^l
low == high 完成划分
right subArray: 49  65  76  97

再对左右子表划分 
右子表一个元素 97 无需划分
左子表65 > 枢轴49 不交换 high--
low == high 确定49位置
右子表65无需划分

自此 所有划分结束
13  27  38  49  49  65  76  97


总结：
快速排序划分实际上可以生成一个二叉树

时间复杂度O(n*递归层数)
best:O(nlog2n)
worst:O(n^2)
空间复杂度O(递归层数)
best:O(log2n)
worst:O(n)

对右有序或者逆序的序列 qs的效率是最差的 因为每次的划分都会不均匀
优化思路：
如果每次选中枢轴元素都是中间的 则划分均匀 递归层数最小 效率最高
eg：随机选择枢轴元素
    每次取首中尾三个元素比较 中间值为枢轴值

快速排序为不稳定算法

*/

#include <iostream>
#include <vector>
#include <chrono>
int partition(std::vector<int>& vi,int low,int high) {
    int pivot = vi[low];    //暂存枢轴
    while (low < high) {    //low == high跳出循环 划分结束 确定枢轴位置
        while (low < high and vi[high] >= pivot) --high;    //如果high的元素大于枢轴元素 high递减
        vi[low] = vi[high];                                 //如果是排好序的 high一直左移 low < high不满足即low == high时 会跳出循环 下面的语句也无效
        while (low < high and vi[low] <= pivot) ++low;
        vi[high] = vi[low];
    }
    vi[low] = pivot;
    return low;
}
void quickSort(std::vector<int>& vi,int low,int high) {     //传入要划分的table 并传入low和high指针
    if (low < high) {                                       //low < high 进行划分
        int pivotPosition = partition(vi,low,high);         //call partition函数 进行划分
        quickSort(vi,low,pivotPosition-1);      //划分左子表
        quickSort(vi,pivotPosition+1,high);     //划分右子表
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
    
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(array,0,array.size()-1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "程序运行时间：" << duration.count() << " 微秒" << std::endl;

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

 /*
 prompt:
 1.while (low < high and vi[high] >= pivot) --high;     是vi[high] >= pivot 不是high >= pivot

2.优化思路 选取枢轴
int pivot;
int mid = vi[(low+high)/2];
if (vi[low] >= vi[mid] && vi[high] <= vi[mid]) {
    pivot = vi[mid];
}else if (vi[low] <= vi[mid] && vi[low] >= vi[high]) {
    pivot = vi[low];
}else {
    pivot = vi[high];
}

 */
