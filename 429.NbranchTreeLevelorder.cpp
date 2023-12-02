/*
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

示例 1：

输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]

示例 2：

输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]

*/

#include <iostream>
#include <vector>
#include <queue>
// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> ret;
        std::queue<Node*> q;
        if (root == nullptr) {
            return ret;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            std::vector<int> vi;
            while (size--) {
                Node* temp = q.front();
                q.pop();
                vi.push_back(temp->val);
                for (Node*& i:temp->children) {
                    q.push(i);
                }
            }
            ret.push_back(vi);
        }
        return ret;
    }
};