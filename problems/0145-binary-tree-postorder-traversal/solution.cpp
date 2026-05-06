// 145. Binary Tree Postorder Traversal
// Difficulty: Easy
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Runtime: 0 ms (beats —)
// Memory: 13.2 MB (beats —)
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

vector <int> res; 
    vector<int> postorderTraversal(TreeNode* root) {
      
      if(root == nullptr) {
          return res;
      }
      
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      res.push_back(root->val);
      
      return res;
    }
    
    
};
