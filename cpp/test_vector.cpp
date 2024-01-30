
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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n < 2) return n;
        vector<int> dp(n+1,0);
        // dp[0] = 0;
        // dp[1] = 0;
        // dp[2] = 0;
        //dp[i]为爬到第i层的最小花费
        for (int i = 3;i <= n;i++) {
            dp[i] = std::min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        for (int& vi:dp) {
            cout << vi << " ";
        }
        cout << endl;
        for (int i = 0;i <= n;i++) cout << i << " ";
        return dp[n];
    }
};
int main() {
    //Create test object
    std::vector<int> array;
    buildArray(array);
    //#############################################################################################
    Solution A;
    int ans = A.minCostClimbingStairs(array);
    
    cout << "ret = " << ans << endl;
    
    //#############################################################################################
    std::cout << "quick sort:" << std::endl; print(array);
}
void buildArray(std::vector<int>& nums) {
    nums = {1,100,1,1,1,100,1,1,100,1};
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
