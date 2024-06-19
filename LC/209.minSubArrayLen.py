from typing import*
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n + 1
        left = 0
        sum = 0
        for right,value in enumerate(nums):
            sum += value
            while sum >= target:
                ans = min(right - left + 1,ans)
                sum -= nums[left]
                left += 1
        return ans if ans <= n else 0
