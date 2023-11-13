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