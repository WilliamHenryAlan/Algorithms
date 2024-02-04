# Definition for a binary tree node.
from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
review 2024.2.3

"""
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
    

class Solution:
    depth = 0
    res = 0
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.traversal(root)
        return self.res
    def traversal(self,root:TreeNode):
        if not root:
            return
        if not root.left and root.right:
            res = max(res,self.depth)
        self.depth += 1
        self.maxDepth(root.left)
        self.maxDepth(root.right)
        self.depth -= 1
