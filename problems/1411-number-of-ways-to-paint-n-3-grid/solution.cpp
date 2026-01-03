// 1411. Number of Ways to Paint N × 3 Grid
// Difficulty: Hard
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Runtime: 0 ms (beats —)
// Memory: 7.9 MB (beats —)
// Submitted: 2026-01-03

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;

        long long same = 6; 
        long long diff = 6; 

        for (int i = 2; i <= n; i++) {
            long long newSame = (same * 3 + diff * 2) % MOD;
            long long newDiff = (same * 2 + diff * 2) % MOD;

            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % MOD;
    }
};
