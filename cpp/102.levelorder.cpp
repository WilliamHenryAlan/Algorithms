#include<iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
solution:
层序遍历属于BFS(Board first search)
1.先判断root是不是nullptr 如果是 return root
2.然后 因为root != nullptr 压栈
3.第一个while循环 把要处理的Node压栈
4.因为queue的size在不断变化 所以应该记录queue的size
5.第二个while循环处理第一个while循环压入栈中的Node condition为size ！= 0
6.循环中处理Node 把value存入vector 并且把当前Node的左右孩子入队

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
/*
review 2024.1.29
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        std::vector<std::vector<int>> ret;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> level;
            while (size--) {
                TreeNode* temp = q.front();
                level.emplace_back(temp->val);
                q.pop();
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
            ret.emplace_back(level);
        }
        return ret;
    }
};