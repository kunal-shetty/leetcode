// 112. Path Sum
// Difficulty: Easy
// https://leetcode.com/problems/path-sum/
// Runtime: 0 ms (beats —)
// Memory: 21.6 MB (beats —)
// Submitted: 2026-02-18

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right) {
            return targetSum - root->val == 0;
        }

        targetSum -= root->val;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);        
    }
};
