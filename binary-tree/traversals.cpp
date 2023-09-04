/**
* @file traversals.cpp
* @brief 二叉树的遍历
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-09-03
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        explicit TreeNode(int x) :  val(x), left(nullptr), right(nullptr) {}
    };

    /**
     * @brief 前序遍历
     * @param node
     * @param vec
     */
    void preorderTraver(TreeNode* node, vector<int>& vec) {
        if (node == nullptr) {
            return;
        }
        vec.push_back(node->val);
        preorderTraver(node->left, vec);
        preorderTraver(node->right, vec);
    }

    /**
     * @brief 迭代前序遍历
     * @param root
     * @return
     */
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> result;
        if (root == nullptr) return result;
        sta.push(root);
        while (!sta.empty()) {
            TreeNode* node = sta.top();
            sta.pop();
            result.push_back(node->val);
            if (node->right) sta.push(node->right);
            if (node->left) sta.push(node->left);
        }
        return result;
    }

    /**
     * @brief 中序遍历
     * @param node
     * @param vec
     */
    void inorderTraver(TreeNode* node, vector<int>& vec) {
        if (node == nullptr) {
            return;
        }
        inorderTraver(node->left, vec);
        vec.push_back(node->val);
        inorderTraver(node->right, vec);
    }

    /**
     * @brief 迭代中序遍历
     * @param root
     * @return
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }

    /**
     * @brief 后续遍历
     * @param node
     * @param vec
     */
    void postorderTraver(TreeNode* node, vector<int>& vec) {
        if (node == nullptr) {
            return;
        }
        postorderTraver(node->left, vec);
        postorderTraver(node->right, vec);
        vec.push_back(node->val);
    }

    /**
     * @brief 迭代后续遍历
     * @param root
     * @return
     */
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    /**
     * @brief 非递归层序遍历
     * @param root
     * @return
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }

    void levelOrder(TreeNode* cur, vector<vector<int>>& result, int depth) {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        levelOrder(cur->left, result, depth+1);
        levelOrder(cur->right, result, depth+1);
    }

    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        levelOrder(root, result, depth);
        return result;
    }




private:
    // TreeNode* root;
};

int main() {
    Solution s;
    return 0;
}

