from typing import *
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort() # 相向双指针前提是排好序
        ret = []
        length = len(nums)
        for i in range(length-2):
            if nums[i] > 0:     # 优化1:如果nums[i] > 0 说明不会有新的三元组出现 return
                return ret
            if nums[i] + nums[-1] + nums[-2] < 0 : # 优化2: 如果第一个元素+最后两个最大的元素大于0 直接迭代i
                continue
            if i > 0 and nums[i] == nums[i-1]: # 对第一个元素进行去重
                continue
            left = i+1
            right = length-1
            while left < right :
                sum = nums[left]+nums[right]
                if sum + nums[i] == 0:
                    ret.append([nums[i],nums[left],nums[right]])
                    left = left+1
                    right = right-1
                    while left < right and nums[left-1] == nums[left]:  # 去重
                        left = left+1
                    while left < right and nums[right+1] == nums[right]:
                        right = right-1
                elif sum + nums[i] > 0:     # 相向双指针判别
                    right = right-1
                else:
                    left = left+1
        return ret
# 时间复杂度 O(n^2)
# 空间复杂度 O(1)