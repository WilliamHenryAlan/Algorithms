坡度的概念为左子树节点之和 - 右子树节点之和的绝对值
可以确定用 postorder  采集 left child sum  and  right child sum 
使用 global variable   tilt初始化为0  累加坡度

class Solution {
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root) {
            if (root == nullptr) return 0;
            int left_sum = dfs(root->left);
            int right_sum = dfs(root->right);
            tilt += abs(left_sum - right_sum);
            return left_sum + right_sum + root->val;
        };
        dfs(root);
        return tilt;
    }
};
