// 62. Unique Paths
// Difficulty: Medium
// https://leetcode.com/problems/unique-paths/
// Runtime: 0 ms (beats —)
// Memory: 7.9 MB (beats —)
// Submitted: 2026-09-15

class Solution {
public:
    int uniquePaths(int m, int n) {
        long res = 1;
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++)
            res = (res * i) / j;
        return res;
    }
};
