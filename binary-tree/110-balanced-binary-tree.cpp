/**
* @file 110-balanced-binary-tree.cpp
* @brief 110. 平衡二叉树
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-04
* @details https://leetcode.cn/problems/balanced-binary-tree/
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};

int main() {
    Solution s;
    return 0;
}
