from typing import *
# 相向双指针 前提是已经排好序了
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers)-1
        while l < r:
            sum = numbers[l] + numbers[r]
            if sum == target:
                return [l+1,r+1]        # 题目要求return index+1        
            elif sum > target:
                r -= 1
            else:
                l += 1
        return []