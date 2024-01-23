class Solution(object):
    def twoSum(self, numbers, target):
        l=0
        r=len(numbers)-1
        while l < r:
            temp = numbers[l]+numbers[r]
            if temp == target:
                return [l+1,r+1]
            elif temp > target:
                r = r-1
            else :
                l = l+1
            
        return []
        