值不相同的 inorder and  preorder 可以确定 唯一 二叉树

难点在于对边界条件处理

1. preorder 可以找到 root 

2. 找到 root 之后 可以在 inorder 找到root 的 index  然后把数组划分为左右两个子数组 也就是两个子树

3. 分治处理


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> um;//记录inorder下标 用于快速找到pivot 也可以while遍历 时间复杂度相同
        int preLen = preorder.size(),inLen = inorder.size();
        for (int i = 0;i < inLen;i++) um[inorder[i]] = i;
        function<TreeNode*(int,int,int,int)> build = 
        [&](int preLeft,int preRight,int inLeft,int inRight) -> TreeNode* { //左右子树边界
            if (preLeft > preRight || inLeft > inRight) return nullptr;
            int pivotVal = preorder[preLeft];                               //确定pivot的值
            TreeNode* root = new TreeNode(pivotVal);
            int pivotIndex = um[pivotVal];                                  //根据值在inorder中找index
            //传入左右子树的新的边界 分治处理
            root->left = build(preLeft + 1,pivotIndex - inLeft + preLeft,inLeft,pivotIndex - 1);
            root->right = build(pivotIndex - inLeft + preLeft + 1,preRight,pivotIndex + 1,inRight);
            return root;
        };
        return build(0,preLen - 1,0,inLen - 1);
    }
};