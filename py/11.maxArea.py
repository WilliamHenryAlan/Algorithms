from typing import *
class Solution:
    def maxArea(self, height: List[int]) -> int:
        length = len(height)
        res = 0
        l = 0
        r = length-1
        for i in range(0,length):
            contain = (r-l) * min(height[l],height[r])
            res = max(res,contain)
            if (height[l] >= height[r]):
                r -= 1
            else:
                l += 1
        return res
