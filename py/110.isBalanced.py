# Definition for a binary tree node.
from typing import *
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def getHeight(root):
            if root is None:    
                return 0    # 如果只有root 左右都是null return 0 + 1 也就是root高度为1 符合题意
            l_height = getHeight(root.left)
            r_height = getHeight(root.right)    # 分别计算左右高度
            if l_height == -1 or r_height == -1:    # 如果 == -1 说明不平衡
                return -1
            if abs(l_height-r_height) > 1:      # 如果左右子树高度差大于1 说明不平衡
                return -1
            return max(l_height,r_height) + 1   # 返回子树高度高的结果 + 1
        return getHeight(root) != -1
            