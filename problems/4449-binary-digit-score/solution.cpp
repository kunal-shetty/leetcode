// 4449. binary digit score
// Difficulty: Unknown
// https://leetcode.com/problems/binary-digit-score/
// Runtime: 1 ms (beats 7.7%)
// Memory: 8.5 MB (beats 92.3%)
// Submitted: 2026-10-25

class Solution {
public:
    int calculateScore(int a, int b) {
        if(__builtin_popcount(a) >= __builtin_popcount(b)) return __builtin_popcount(a) * __builtin_popcount(b);
        return (int)__builtin_popcount(b) / (int)__builtin_popcount(a);
        
    }
};
