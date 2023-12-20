/*
2023.12.20
*/


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