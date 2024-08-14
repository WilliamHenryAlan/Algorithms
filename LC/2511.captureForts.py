class Solution:
    def captureForts(self, forts: List[int]) -> int:
        ans = 0
        for i,x in enumerate(forts):
            if x != 1:continue
            j = i - 1
            while j >= 0 and forts[j] == 0:j -= 1
            if j >= 0 and forts[j] == -1:
                ans = max(i - j - 1,ans)
            j = i + 1
            while j < len(forts) and forts[j] == 0:j += 1
            if j < len(forts) and forts[j] == -1:
                ans = max(j - i - 1,ans)
        return ans
