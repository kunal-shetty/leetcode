// 94. Binary Tree Inorder Traversal
// Difficulty: Easy
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Runtime: 0 ms (beats —)
// Memory: 13.5 MB (beats —)
// Submitted: 2026-05-06

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
vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};
