// 3760. Maximum Substrings With Distinct Start
// Difficulty: Medium
// https://leetcode.com/problems/maximum-substrings-with-distinct-start/
// Runtime: 29 ms (beats —)
// Memory: 25.4 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> chars;
        for(auto c : s) chars.insert(c);
        return chars.size();
    }
};
