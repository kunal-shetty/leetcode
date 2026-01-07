// 1339. Maximum Product of Splitted Binary Tree
// Difficulty: Medium
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Runtime: 8 ms (beats —)
// Memory: 78.2 MB (beats —)
// Submitted: 2026-01-07

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
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    // Postorder traversal to calculate subtree sums
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subTreeSum = root->val + left + right;

        // Try cutting here
        maxProd = max(maxProd, subTreeSum * (totalSum - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        // First pass: get total sum
        dfs(root);
        
        totalSum = 0;
        calculateTotal(root);

        // Second pass: compute max product
        maxProd = 0;
        dfs(root);

        return maxProd % MOD;
    }

private:
    void calculateTotal(TreeNode* root) {
        if (!root) return;
        totalSum += root->val;
        calculateTotal(root->left);
        calculateTotal(root->right);
    }
};
