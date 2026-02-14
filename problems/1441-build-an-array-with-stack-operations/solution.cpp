// 1441. Build an Array With Stack Operations
// Difficulty: Medium
// https://leetcode.com/problems/build-an-array-with-stack-operations/
// Runtime: 0 ms (beats —)
// Memory: 10.7 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int j = 0;  
        
        for(int i = 1; i <= n && j < target.size(); i++) {
            operations.push_back("Push");
            
            if(i == target[j]) {
                j++;  
            } else {
                operations.push_back("Pop");  
            }
        }
        
        return operations;
    }
};
