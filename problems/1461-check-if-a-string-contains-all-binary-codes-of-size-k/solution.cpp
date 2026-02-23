// 1461. Check If a String Contains All Binary Codes of Size K
// Difficulty: Medium
// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Runtime: 425 ms (beats —)
// Memory: 119.1 MB (beats —)
// Submitted: 2026-02-23

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string> nums;
        
        for (int i = 0; i <= s.size() - k; i++)
            nums.insert(s.substr(i, k));
        
        return nums.size() == pow(2, k);
    }
};
