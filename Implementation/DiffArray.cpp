
#include <iostream>
#include <vector>
using namespace std;
/*
1.差分数组
假定nums = [1,3,3,4,5,8,3,5]
差分数组d = [1,2,0,1,1,3,-5,2]
difference array的定义:

2.d[i] = d[i] = a[i] - a[i - 1] ,i >= 1
       = a[0] ,i = 0

3.差分数组性质1:由差分数组可以推回原数组
4.差分数组性质2:把原数组a[i],a[i+1]...a[j]加上x <=> d[i] + x && d[j + 1] - x

*/
void print(const std::vector<int>& vi);
class DiffArray {
public:
    vector<int> diff;
    DiffArray(vector<int>& nums) {
        int len = nums.size();
        diff.resize(len,0);
        diff[0] = nums[0];  //保留第一个元素
        for (int i = 1;i < len;i++) {   //保留第一个element 从第二个开始
            diff[i] = nums[i] - nums[i - 1];
        }
    }
    void recover() {
        for (int i = 1;i < diff.size();i++) {
            diff[i] += diff[i - 1];
        }
    }
};

int main() {
    vector<int> nums {1,3,3,4,5,8,3,5};
    DiffArray d(nums);
    cout << "原数组:";print(nums);
    cout << "差分  :";print(d.diff);
    cout << "nums[1] ~ nums[6]整体数据+10" << endl;
    for (int i = 1;i <= 6;i++) nums[i] += 10;
    DiffArray d2(nums);
    cout << "原数组:";print(nums);
    cout << "差分  :";print(d2.diff);
    d2.recover();
    cout << "recover()复原:";print(d2.diff);
}

void print(const std::vector<int>& vi) {
    std::cout << "array:  ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}