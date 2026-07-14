// 3336. Find the Number of Subsequences With Equal GCD
// Difficulty: Hard
// https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/
// Runtime: 1029 ms (beats —)
// Memory: 315.5 MB (beats —)
// Submitted: 2026-07-14

class Solution {
public:
    int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {

        vector<vector<int>> curr(201, vector<int>(201, 0));
        vector<vector<int>> next(201, vector<int>(201, 0));

        curr[0][0] = 1;

        for (int x : nums) {

            for (int i = 0; i <= 200; i++)
                fill(next[i].begin(), next[i].end(), 0);

            for (int g1 = 0; g1 <= 200; g1++) {
                for (int g2 = 0; g2 <= 200; g2++) {

                    if (curr[g1][g2] == 0)
                        continue;

                    long long ways = curr[g1][g2];

                    next[g1][g2] = (next[g1][g2] + ways) % MOD;

                    int ng1 = (g1 == 0 ? x : gcd(g1, x));
                    next[ng1][g2] = (next[ng1][g2] + ways) % MOD;

                    int ng2 = (g2 == 0 ? x : gcd(g2, x));
                    next[g1][ng2] = (next[g1][ng2] + ways) % MOD;
                }
            }

            swap(curr, next);
        }

        long long ans = 0;

        for (int g = 1; g <= 200; g++)
            ans = (ans + curr[g][g]) % MOD;

        return ans;
    }
};
