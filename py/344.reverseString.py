class Solution:
    def reverseString(self, s: List[str]) -> None:
        n = len(s)
        l = 0
        r = n-1
        while l < r:
            temp = s[l]
            s[l] = s[r]
            s[r] = temp
            l += 1
            r -= 1