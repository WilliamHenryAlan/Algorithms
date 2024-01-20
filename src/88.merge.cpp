
#include <iostream>
#include <vector>
using namespace std;
/*
Method 1:quick sort
*/
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for (int i = 0; i < n;i++) {
            nums1[m+i] = nums2[i];
        }        
        std::sort(nums1.begin(),nums1.end());
    }
};

/*
Method 2:双指针
        i
nums1:  1,2,3,0,0,0
nums2:  2,5,6
        j
1.i和j分别指向两个数组进行遍历 i < m || j < n
2.当nums1[i] <= nums2[j]时 
                        res.push_back(nums1[i++]); 赋值并指针i++
  当nums1[i] > nums2[j]时 
                        res.push_back(nums2[j++]); 赋值并指针j++
3.检查边界情况：    
            1.i先遍历完 所以当i < m 才res.push_back(nums1[i++]) 或者说 当i >= m时 执行res.push_back(nums2[j++]);
            2.j先遍历完 当j >=n 时 只执行 res.push_back(nums1[i++]); 赋值并指针i++
4.考虑优化 内存
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> res;
        for (int i = 0,j = 0;i < m || j < n;) {
            if (j >= n || i < m && nums1[i] <= nums2[j]) {
                res.push_back(nums1[i++]);
            }else {
                res.push_back(nums2[j++]);
            }
        }
        nums1 = res;
    }
};
/*
如果在nums1中原地遍历 会造成数据丢失的情况 但是nums1中末尾的0其实无所谓
所以可以考虑 从后向前遍历
优化内存之后：
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        
    }
};
