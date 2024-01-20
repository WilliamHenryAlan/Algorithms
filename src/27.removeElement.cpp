/*
2023.12.20
*/

/*
issue:删除数组中的元素
solution：
设置快慢指针
慢指针之前的元素是更新后的数组 慢指针所在的是待更新区域 快指针寻找更新元素

1.设置slow fast指针指向index 0
2.当fast指针从头开始寻找 如果不是待删除元素 就赋值给slow指针 然后继续迭代
                        如果是待删除元素 slow指针不动 指向待更新区域 迭代fast
3.loop每次迭代fast 当不是待删除元素时才迭代slow
4.slow指针从0开始计数更新的数组 就是新数组的长度
*/
#include <iostream>
#include <vector>
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int len = nums.size();
        int slow = 0, fast = 0;
        for (;fast < len;fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

/*
Solution:
1.采用双指针 slow=0 fast=0
2.slow更新最新vector fast寻找与target不相等的并更新slow
3.因为slow在更新之后++ 始终指向下一个元素 所以return slow而不是slow+1
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        int slow=0;
        for (int fast=0;fast<len;fast++)
        {
            if (nums[fast]!=val)
            {
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
int main()
{
    vector<int> vi;
    vi.push_back(3);
    vi.push_back(2);
    vi.push_back(2);
    vi.push_back(3);
    Solution t;
    for (int out:vi)
        cout << " " << out;
    cout << endl;
    cout << "new vector length is " << t.removeElement(vi,3) << endl;
    for (int out:vi)
        cout << " " << out;
}


//VersionB
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int len=nums.size();
//         for (int i=0;i<len;)
//         {
//             if (nums[i]==val)
//             {
//                 for (int j = i; j < len; j++)
//                 {
//                     nums[j]=nums[j+1];
//                 }
//                 len--;
//             }
//             else i++;
//         }
//         return len;
//     }
// };