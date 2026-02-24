// 1022. Sum of Root To Leaf Binary Numbers
// Difficulty: Easy
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
// Runtime: 0 ms (beats —)
// Memory: 17.2 MB (beats —)
// Submitted: 2026-02-24

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int x) {
        if (root == nullptr) return 0;
        x = x * 2 + root->val;
        if (root->left == root->right) return x;
        return dfs(root->left, x) + dfs(root->right, x);
    }
};
