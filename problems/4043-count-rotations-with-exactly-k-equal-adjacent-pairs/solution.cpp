// 4043. Count Rotations With Exactly K Equal Adjacent Pairs
// Difficulty: Easy
// https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
// Runtime: 1 ms (beats —)
// Memory: 9.4 MB (beats —)
// Submitted: 2026-09-06

class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size(), score = 0, res = 0;
        for(int i = 0; i < n- 1; i++) score += s[i] == s[i + 1];
        res += score == k;
        int r = s[0] == s.back();
        for(int i  = 1; i < n; i++){
                res += score - (s[i - 1] == s[i]) + r == k;
        }
        return res;
    }
};
