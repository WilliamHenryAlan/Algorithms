
/*
        /冒泡排序
交换排序
        \快速排序

快速排序思想：
1.从表中选取一个元素作为pivot(枢轴或者基准)
2.升序为例作划分 low和high指针指向头尾 把表划分为两个部分 枢轴左边的要比枢轴小 右边的要比枢轴大

总结：
快速排序划分实际上可以生成一个二叉树 是preorder

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
using namespace std;
int partition(std::vector<int>& vi,int low,int high);
void quickSort(std::vector<int>& vi,int low,int high);
void buildArray(std::vector<int>& nums);
void print(const std::vector<int>& vi);
class Solution {
public:
    void backtracking(int startIndex,int n,int k,vector<int>& path,vector<vector<int> >& ret) {
        //写循环终止条件 也就是leafNode 当path元素个数为k时 得到答案
        if (path.size() == k) {
            ret.emplace_back(path);
            return;
        }
        for (int i = startIndex;i <= n;++i) {
            path.emplace_back(i);           //每次push进去 进行递归 如果满足leafNode条件
            backtracking(i+1,n,k,path,ret);
            path.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> path;
        vector<vector<int> > ret;
        backtracking(1,n,k,path,ret);
        return ret;
    }
};
int main() {
    //Create test object
    std::vector<int> array;
    //#############################################################################################
    Solution A;
    vector<vector<int> > ans = A.combine(4,2);
    for (vector<int>& vi:ans) {
        print(vi);
        cout << " ";
    }
    
    //#############################################################################################
    std::cout << "quick sort:" << std::endl; print(array);
}
void buildArray(std::vector<int>& nums) {
    nums.push_back(49);
    nums.push_back(38);
    nums.push_back(76);
    nums.push_back(39);
    nums.push_back(29);
    nums.push_back(19);
    std::cout << "Array created successfully" << std::endl;
    print(nums);
}
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
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
