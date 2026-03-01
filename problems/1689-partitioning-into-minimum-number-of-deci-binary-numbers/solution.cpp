// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// Difficulty: Medium
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Runtime: 3 ms (beats —)
// Memory: 16.7 MB (beats —)
// Submitted: 2026-03-01

class Solution {
public:
    int minPartitions(string n) {
        int largest = n[0] - '0';
        
        for(int i = 0; i < n.length(); i++) {
            largest = max(largest, n[i] - '0');
        }
        
        return largest;
    }
};
