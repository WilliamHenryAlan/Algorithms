# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans,path = [],[]
        sum = 0
        def dfs(root,sum):
            if not root: return
            path.append(root.val)
            sum += root.val
            if sum == targetSum and not root.left and not root.right:
                ans.append(list(path))
            dfs(root.left,sum)
            dfs(root.right,sum)
            path.pop()
        dfs(root,0)
        return ans

