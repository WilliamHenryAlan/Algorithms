 1.不一定要经过root 比如 

           5

        /    

       4           

    /    \           

  1        3           

/            \

7              9

最长直径为 [7->1->4->3->6]  为 4 




 2.直径为边的数量 比如 

             5

        /        \

       4           3

    /    \           \

  7        3           8                     

最长直径为 [7->4->5->3->6] or  [3->4->5->3->6]为 4 




观察可知 最长直径一定是两个 leaf node 的最长距离

所以 假设每一个node都为拐弯的node 则他的左右子树的leaf node 长度为最大直径 和求二叉树最大深度类似

所以 对于每一个node 最大直径为左子树长度+右子树长度+2



class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* p) {
            if (p == nullptr) return -1;
            int l = dfs(p->left);
            int r = dfs(p->right);
            ans = max(ans,l + r + 2);
            return max(l,r) + 1;
        };
        dfs(root);
        return ans;
    }
};
