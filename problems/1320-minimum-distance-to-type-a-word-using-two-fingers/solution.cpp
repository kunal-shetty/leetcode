// 1320. Minimum Distance to Type a Word Using Two Fingers
// Difficulty: Hard
// https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
// Runtime: 0 ms (beats —)
// Memory: 8.4 MB (beats —)
// Submitted: 2026-04-12

class Solution {
public:
    int dp[300][27];

    int dist(int x, int y) {
        if (x == 26 || y == 26) return 0;
        return abs(x / 6 - y / 6) + abs(x % 6 - y % 6);
    }

    int minimumDistance(string& word) {
        int n = word.size();
        const int INF = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 27; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][26] = 0;

        int prev = word[0] - 'A';

        for (int i = 1; i < n; i++) {
            int curr = word[i] - 'A';

            for (int j = 0; j < 27; j++) {
                if (dp[i - 1][j] == INF) continue;

                dp[i][j] = min(dp[i][j],
                               dp[i - 1][j] + dist(prev, curr));

                dp[i][prev] = min(dp[i][prev],
                                  dp[i - 1][j] + dist(j, curr));
            }

            prev = curr;
        }

        int ans = INF;
        for (int j = 0; j < 27; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};
