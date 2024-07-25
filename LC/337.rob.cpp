/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*
 1.确认遍历顺序 后序遍历可以把左右孩子节点的数据进行收集

2.明确dp含义 dp[0]为偷 dp[1]为不偷  

3.每次对于当前节点 确认偷和不偷的最大可获得价值  

    1.偷 那么child node就不能偷了 则 = child node的不偷值 + 当前节点的值

    2.不偷 那么 = left tree可偷取最大值 + right tree可偷取最大值 注意：parent node不偷时 child node不一定偷的时候才是最大的

 */
class Solution {
public:
    int rob(TreeNode* root) {
        function<vector<int>(TreeNode*)> dfs = [&](TreeNode* x) {
            vector<int> arr(2,0),l,r;
            if (x == nullptr) return arr;
            l = dfs(x->left);
            r = dfs(x->right);
            arr[0] = x->val + l[1] + r[1];
            arr[1] = max(l[0], l[1]) + max(r[0], r[1]);
            return arr;
		};
        vector<int> ans = dfs(root);
        return max(ans[0],ans[1]);
    }
};
