// 3993. Maximum Value of an Alternating Sequence
// Difficulty: Medium
// https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/
// Runtime: 0 ms (beats —)
// Memory: 9 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    long long maximumValue(int n, int s, int m) {
      if(n == 1) return s;
    long long peak = n /2;
        return s + peak * m - (peak - 1);
    }
};
