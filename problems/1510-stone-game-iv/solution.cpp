// 1510. Stone Game IV
// Difficulty: Hard
// https://leetcode.com/problems/stone-game-iv/
// Runtime: 0 ms (beats —)
// Memory: 8.9 MB (beats —)
// Submitted: 2026-08-10

class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<bool> dp(n + 1);
        for (int i = 0; i <= n; i++) {

            if (!dp[i]) {

                for (int j = 1; i + j * j <= n; j++) {
                    dp[i + j * j] = true;
                }

                if (dp[n]) {
                    return true;
                }
            }
        }

        return false;
    }
};
