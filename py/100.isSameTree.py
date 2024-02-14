# Definition for a binary tree node.
from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None or q is None:
            return p is q
        return p.val == q.val and self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)


class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        def f(p,q):
            if p is None and q is not None:
                return False
            if p is not None and q is None:
                return False
            if p is None and q is None:
                return True
            if p.val != p.val:
                return False
            return f(p.left,q.left) and f(p.right,q.right)
        return f(p,q)
    
