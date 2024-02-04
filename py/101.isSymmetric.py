# Definition for a binary tree node.
from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
review 2024.2.3
tips:
逻辑是leftChild->left == rightChild->right
     leftChild->right == rightChild->left
"""
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return root
        return self.traversal(root.left,root.right)
    def traversal(self,l:TreeNode,r:TreeNode):
        if not l and not r:
            return True
        if not l and r:
            return False
        if l and not r:
            return False
        if l.val != r.val:
            return False
        return self.traversal(l.left,r.right) and self.traversal(l.right,r.left)