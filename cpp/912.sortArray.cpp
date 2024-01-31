#include <iostream>
#include <vector>
using namespace std;

/*
merge sort
*/
class Solution {
public:
    vector<int> temp;
    void mergeSort(vector<int>& nums,int left,int right) {
        if (left >= right) return;
        int middle = (left+right)/2;
        mergeSort(nums,left,middle);
        mergeSort(nums,middle+1,right);
        //merge
        int i = left,j = middle+1;
        int cnt = 0;
        while (i <= middle && j <= right) {
            if (nums[i] <= nums[j]) temp[cnt++] = nums[i++];
            else temp[cnt++] = nums[j++];
        }
        while (i <= middle) temp[cnt++] = nums[i++];
        while (j <= right) temp[cnt++] = nums[j++];
        for (int i = left;i <= right;i++) nums[i] = temp[i-left];
    }
    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};