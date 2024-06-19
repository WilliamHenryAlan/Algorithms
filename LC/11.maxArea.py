class Solution:
    def maxArea(self, height: List[int]) -> int:
        r = len(height) - 1
        ans = 0
        l = 0
        while l < r:
            area = min(height[l],height[r]) * (r - l)
            ans = max(ans,area)
            if height[l] >= height[r]:
                r -= 1
            else:
                l += 1
        return ans
