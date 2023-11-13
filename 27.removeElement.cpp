#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int len=nums.size();
        for (int i = 0,j=0; i < len; j++)
        {
            if (nums[i]==nums[j])
            {
                count++;
            }else
            {
                nums[++i]=nums[j];
            }
        }
        return len-count;
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
    t.removeElement(vi,)
}