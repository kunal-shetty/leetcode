// 865. Smallest Subtree with all the Deepest Nodes
// Difficulty: Medium
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Runtime: 0 ms (beats —)
// Memory: 16.2 MB (beats —)
// Submitted: 2026-01-09

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    // Helper function: returns {deepest subtree root, depth}
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {nullptr, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        }
        else if (right.second > left.second) {
            return {right.first, right.second + 1};
        }
        else {
            return {root, left.second + 1};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
};
