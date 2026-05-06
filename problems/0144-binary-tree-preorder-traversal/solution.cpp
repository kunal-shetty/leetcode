// 144. Binary Tree Preorder Traversal
// Difficulty: Easy
// https://leetcode.com/problems/binary-tree-preorder-traversal/
// Runtime: 3 ms (beats —)
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};
