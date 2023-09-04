/**
* @file 101-symmetric-tree.cpp
* @brief 101. 对称二叉树
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-04
* @details https://leetcode.cn/problems/symmetric-tree/
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

    bool compare(TreeNode* left, TreeNode* right) {
        // 首先排除空节点的情况
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }

};

int main() {
    Solution s;
    return 0;
}
