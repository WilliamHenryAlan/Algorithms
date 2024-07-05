#include <iostream>
#include <vector>

/*
review 2024.7.5
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;//
        int low=0;
        int hight=nums.size()-1;
        int mid;
        while (low<=hight)
        {
            mid = (low+hight)/2;
            int temp=nums[mid];
            if (target == temp)
            {
                return mid;
            }
            else if (target > temp)
            {
                low=mid+1;
            }
            else 
            {
                hight=mid-1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution t;
    std::vector<int> vi;
    for (int i = 0;i < 10;i++)
    vi.push_back(i);
    std::cout << "The index = " << t.Solution::search(vi,4) << std::endl;
}