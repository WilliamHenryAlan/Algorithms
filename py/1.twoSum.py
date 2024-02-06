class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        n = len(nums)
        for i in range(n):
            if target-nums[i] in hash:
                return [hash[target-nums[i]],i]
            hash[nums[i]] = i   # 注意细节 不是hash[target - nums[i]] = i
        return []



