class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return list()
        phoneMap = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}
        path= []
        ans = []
        def backtracking(index):
            if index == len(digits):
                ans.append("".join(path))
                return
            s = phoneMap[index]
            for c in s:
                path.append(c)
                backtracking(index+1)
                path.pop()
        backtracking(0)
        return ans
                