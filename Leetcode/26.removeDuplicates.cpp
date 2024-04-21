#include <vector>
#include <iostream>
using namespace std;

/*
review 2024.2.15
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 0;j < nums.size();j++) {
            if (nums[j] != nums[i]) nums[++i] = nums[j];
        }
        return i+1;
    }
};

/*
2023.12.20
*/
/*
issue:删除有序数组中的重复项
solution:
采用双指针思路：i指针及之前的数组是更新之后的数组 i指针指向下一个需要更新的位置 j指针寻找更新元素
由于给定的数组 nums是有序的，相等的元素在数组中的下标一定是连续的。利用数组有序的特点，可以通过双指针的方法删除重复元素。

1.创建i = 0，j = 0
2.loop：条件为快指针j < 数组长度
3.如果快指针的值等于慢指针 什么都不用做 迭代快指针
4.如果快指针的值不等于慢指针 说明找到了可以更新的元素 这时候应该要把慢指针的下一个位置 赋值为快指针的值 并且快慢指针迭代
5.总结快指针无论哪种情况都要迭代 只有快指针找到了不同的值 慢指针才迭代
6.因为慢指针及之前都是更新的数组 所以数组的长度为i+1
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,j = 0;
        int len = nums.size();
        while (j < len) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
            j++;
        }
        return i+1;
    }
};



/*
1.两个伪指针index指向index0和1，遍历vector，每次j++
2.如果nums[j]!=nums[i] 
        nums[i+1]=nums[j] 把i指针的下一个元素等于新的不重复的元素
        i指针后移
3.loop结束 返回i+1为不重复元素的数组长度
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        int i=0,j=1;        //1.
        while (j<len)
        {
            if (nums[i]!=nums[j])   //2.
            {
                nums[++i]=nums[j];
            }
            j++;
        }
        return i+1;     //3.
    }
};

int main()
{
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(1);
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(4);
    vi.push_back(4);
    vi.push_back(4);
    Solution t;
    t.removeDuplicates(vi);
    for (int element:vi)
    {
        std::cout << " " << element;
    }
}

//Version B
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int size = nums.size();
//         if (size <= 0) return 0;
//         int index,fast;
//         for (index = 0,fast = 0;fast < size;)
//         {
//             if (nums[index] == nums[fast])
//             {
//                 fast++;
//             }
//             else
//             {
//                 nums[index+1] = nums[fast];
//                 index++;
//             }
//         }
//         return index+1;
//     }
//  };

//Version C
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int count=0;
//         int len=nums.size();
//         for (int i = 0,j=0; j < len; j++)
//         {
//             if (nums[i]==nums[j])
//             {
//                 count++;
//             }else
//             {
//                 nums[++i]=nums[j];
//             }
//         }
//         return len-count;
//     }
// };