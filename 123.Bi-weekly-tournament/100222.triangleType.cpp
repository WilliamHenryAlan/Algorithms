#include<iostream>
#include <vector>
using namespace std;
/*
给你一个下标从 0 开始长度为 3 的整数数组 nums ，需要用它们来构造三角形。

如果一个三角形的所有边长度相等，那么这个三角形称为 equilateral 。
如果一个三角形恰好有两条边长度相等，那么这个三角形称为 isosceles 。
如果一个三角形三条边的长度互不相同，那么这个三角形称为 scalene 。
如果这个数组无法构成一个三角形，请你返回字符串 "none" ，否则返回一个字符串表示这个三角形的类型。
 
*/
class Solution {
public:
    string triangleType(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int x = nums[0], y = nums[1], z = nums[2];
        //排序后 比较短边之和大于第三边
        if (x + y <= z) {
            return "none";  //三角形无法构成
        }
        //排序后 如果x == z 那么x == z && z === y
        if (x == z) {
            return "equilateral";   //等边三角形
        }
        if (x == y || y == z) {
            return "isosceles"; //等腰三角形
        }
        return "scalene";   //普通三角形
    }
};