// 110. Balanced Binary Tree
// Difficulty: Easy
// https://leetcode.com/problems/balanced-binary-tree/
// Runtime: 0 ms (beats —)
// Memory: 22.9 MB (beats —)
// Submitted: 2026-02-08

class Solution {
public:
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        
        int leftheight = dfs(root->left);
        if(leftheight == -1) return -1;
        
        int rightheight = dfs(root->right);
        if(rightheight == -1) return -1;
        
        if(abs(leftheight - rightheight) > 1) return -1;
        
        return max(leftheight, rightheight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
