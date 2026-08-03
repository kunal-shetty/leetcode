// 404. Sum of Left Leaves
// Difficulty: Easy
// https://leetcode.com/problems/sum-of-left-leaves/
// Runtime: 0 ms (beats —)
// Memory: 16.1 MB (beats —)
// Submitted: 2026-08-03

class Solution {
public:
    int dfs(TreeNode* root, bool isLeft) {
        if (root == nullptr) return 0;

        if (isLeft && root->left == nullptr && root->right == nullptr)
            return root->val;

        return dfs(root->left, true) + dfs(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};
