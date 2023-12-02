#include<iostream>
#include <vector>
#include <queue>
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
116
117
104
111
*/
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }
        q.push(root);
        while (!q.empty()) {    //第一个while循环把要处理的Node压入队列
            int size = q.size();    //因为要返回二维数组 q.size()会不断变化 要先记录
            std::vector<int> vi;
            while (size--) {    //第二个while循环处理压入队列的Node
                //TreeNode* temp = q.front();   //因为循环中大量call q.front() 可以保存队头元素减少开销
                vi.push_back(q.front()->val);   //保存一层的value
                //压入下一层的Node
                if (q.front()->left != nullptr) {   //左右孩子不为空 分别压入
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();    //迭代 pop 所以要提前记录size
            }
            ret.push_back(vi);  //不用vi.clear() 直接在上一个while循环里创建本地变量 离开作用域自动消亡
        }
        return ret;
    }
};