/**
* @file 222-count-complete-tree-nodes.cpp
* @brief 222. 完全二叉树的节点个数
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-04
* @details https://leetcode.cn/problems/count-complete-tree-nodes/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int getNodesNum(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int leftNum = getNodesNum(cur->left);
        int rightNum = getNodesNum(cur->right);
        int treeNum = leftNum + rightNum + 1;
        return treeNum;
    }

    int countNodes(TreeNode* root) {
        return getNodesNum(root);
    }
};

int main() {
    Solution s;
    return 0;
}
