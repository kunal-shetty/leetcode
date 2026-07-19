// 3997. Count Dominant Nodes in a Binary Tree
// Difficulty: Medium
// https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/
// Runtime: 0 ms (beats —)
// Memory: 337.2 MB (beats —)
// Submitted: 2026-07-19

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
    int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return INT_MIN;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int cur = max(root->val, max(left, right));
        if(cur == root->val) ans++;

        return cur;
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
