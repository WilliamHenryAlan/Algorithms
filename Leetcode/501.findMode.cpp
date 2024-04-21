#include<iostream>
#include <vector>

using namespace std;
//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* prev = nullptr;
    int freq = 0;
    int maxFreq = 0;
    vector<int> result;
    void traversal(TreeNode* cur) {
        if (!cur) return;
        traversal(cur->left);
        if (!prev) {    //prev为nullptr current指向node freq = 1
            freq = 1;
        }else if (cur->val == prev->val) {  //当值相等时 累加
            freq++;
        }else {
            freq = 1;   //累加结束 值不相等
        }
        prev = cur;     //更新prev指针
        if (freq == maxFreq) {          //如果freq == maxFreq 说明有多个众数
            result.push_back(prev->val);
        }else if (freq > maxFreq) {     //发现frequency更高的元素 清空result 更新maxFreqency 压入新元素
            result.clear();
            maxFreq = freq;
            result.push_back(prev->val);
        }
        traversal(cur->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return result;
    }
};
class Solution {
public:
    unordered_map<int,int> hash;
    bool static cmp(const pair<int,int>& a,const pair<int,int>& b) {
        return a.second > b.second;
    }
    void traversal(TreeNode* root) {
        if (!root) return;
        hash[root->val]++;
        traversal(root->left);
        traversal(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        int ret = 0;
        int count = 0;
        traversal(root);
        vector<pair<int,int>> vi(hash.begin(),hash.end());
        sort(vi.begin(),vi.end(),cmp);
        vector<int> ans;
        ans.push_back(vi[0].first);
        for (int i = 1;i < vi.size();i++) {
            if (vi[i].second == vi[0].second) ans.push_back(i);
        }
        return ans;
    }
};