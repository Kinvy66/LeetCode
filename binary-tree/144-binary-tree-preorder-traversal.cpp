/**
* @file 144-binary-tree-preorder-traversal.cpp
* @brief 144. 二叉树的前序遍历
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-03
* @details https://leetcode.cn/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderTraversal(root, ret);
        return ret;
    }

    void preorderTraversal(TreeNode* node, vector<int>& vec) {
        if (node == nullptr) {
            return;
        }
        vec.push_back(node->val);
        preorderTraversal(node->left, vec);
        preorderTraversal(node->right, vec);
    }

    vector<int> postorderTraversal(TreeNode* root) {

    }
};

int main() {
    Solution s;
    return 0;
}