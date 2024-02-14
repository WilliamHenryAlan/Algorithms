
# Definition for a binary tree node.
from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def f(root,depth):
            if root is None:
                return
            if depth == len(ans):
                ans.append(root.val)
            f(root.right,depth + 1)
            f(root.left,depth + 1)
        f(root,0)
        return ans
