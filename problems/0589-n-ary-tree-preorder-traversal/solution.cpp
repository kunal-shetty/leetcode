// 589. N-ary Tree Preorder Traversal
// Difficulty: Easy
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
// Runtime: 23 ms (beats —)
// Memory: 112.1 MB (beats —)
// Submitted: 2026-05-06

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
vector<int> res;
    vector<int> preorder(Node* root) {
        if(root == nullptr) return res;
        res.push_back(root->val);
        for(auto r : root->children){
            preorder(r);
            }
        return res;
    }
}; 
