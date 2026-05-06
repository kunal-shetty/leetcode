// 590. N-ary Tree Postorder Traversal
// Difficulty: Easy
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// Runtime: 12 ms (beats —)
// Memory: 111.1 MB (beats —)
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
    vector<int> postorder(Node* root) {
        if(root == nullptr) return res;
        for(auto r : root->children){
            postorder(r);
            }
            res.push_back(root->val);
        return res;
    }
};
