

1.先写递归终止条件 到了leaf node 直接return

2.每次到了一个node 先添加到path中去

3.判断当前node是不是leaf node并且此时的targetSum正好等于path中的和 如果是 则添加

4.递归左右子树

5.因为是by reference(c++,python或java中是by object含义类似) 所以在退出之后要pop


//by reference
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        function<void(TreeNode*)> dfs = 
        [&](TreeNode* root) {
            if (root == nullptr) return;
            path.push_back(root->val);
            sum += root->val;
            if (sum == targetSum && root->left == nullptr && root->right == nullptr) 
                ans.push_back(path);
            dfs(root->left);
            dfs(root->right);
            path.pop_back();
            sum -= root->val;
        };
        dfs(root);
        return ans;
    }
};
//by value 效率低
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> vi;
        int s = 0;
        function<void(TreeNode*,vector<int>,int)> dfs = 
        [&](TreeNode* p,vector<int> path,int sum) {
            if (p == nullptr) return;
            path.push_back(p->val);
            sum += p->val;
            if (sum == targetSum && p->left == nullptr && p->right == nullptr) {
                ans.push_back(path);
            }
            dfs(p->left,path,sum);
            dfs(p->right,path,sum);
        };
        dfs(root,vi,s);
        return ans;
    }
};
