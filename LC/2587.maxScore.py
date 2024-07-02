class Solution:
    def maxScore(self, nums: List[int]) -> int:
        nums.sort(reverse = True)
        # ans = s = 0
        # for x in nums:
        #     s += x
        #     if s > 0:
        #         ans += 1
        # return ans
        return sum(s > 0 for s in accumulate(nums))
        
