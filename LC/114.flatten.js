/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    while (root != null) {
            if (root.left == null) {
                root = root.right;
            }else {
                let lr = root.left;
                while (lr.right != null) {
                    lr = lr.right;
                }
                lr.right = root.right;
                root.right = root.left;
                root.left = null;
                root = root.right;
            }
        }
};

