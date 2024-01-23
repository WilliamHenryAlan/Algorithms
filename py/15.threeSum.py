class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = []
        length = len(nums)
        for i in range(length-2):
            if nums[i] > 0:     # 如果nums[i] > 0 说明不会有新的三元组出现 return
                return ret
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left = i+1
            right = length-1
            while left < right :
                sum = nums[left]+nums[right]
                if sum + nums[i] == 0:
                    ret.append([nums[i],nums[left],nums[right]])
                    left = left+1
                    right = right-1
                    while left < right and nums[left-1] == nums[left]:
                        left = left+1
                    while left < right and nums[right+1] == nums[right]:
                        right = right-1
                elif sum + nums[i] > 0:
                    right = right-1
                else:
                    left = left+1
        return ret