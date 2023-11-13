/*
在数组中找出和为target的两个元素 并以数组的形式返回两个下标
*/
#include <iostream>
#include <vector>
std::vector<int> twoSum(std::vector<int>& nums,int target)
{
    if (nums.size() == 0) return nums;  //
    for (int i = 0; i < nums.size()-1; i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[i]+nums[j] == target)
            {
                nums[0]=i;
                nums[1]=j;
                nums.erase(nums.begin()+2,nums.end());
            }
            
        }
        
    }
    return nums;
}

int main()
{
    std::vector<int> vi;
    vi.push_back(2);
    vi.push_back(7);
    vi.push_back(11);
    vi.push_back(15);
    vi=twoSum(vi,9);
    for (int i:vi)
    {
        std::cout << i << " ";
    }
}