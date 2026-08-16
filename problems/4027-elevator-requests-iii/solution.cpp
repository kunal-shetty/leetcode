// 4027. Elevator Requests III
// Difficulty: Hard
// https://leetcode.com/problems/elevator-requests-iii/
// Runtime: 463 ms (beats —)
// Memory: 125.5 MB (beats —)
// Submitted: 2026-08-16

class Solution {
public:
    long long elevatorRequests(int n, int start,
                               vector<vector<int>>& requests) {
        int m = requests.size();
        const long long INF = 1e18;
        vector<vector<long long>> dp(1 << m, vector<long long>(m, INF));
        for (int i = 0; i < m; i++) {
            long long travel = abs(start - requests[i][1]);
            dp[1 << i][i] = max(travel, (long long)requests[i][0]);
        }
        for (int mask = 0; mask < (1 << m); mask++) {
            for (int j = 0; j < m; j++) {
                if (!(mask && (1 << j)))
                    continue;
                if (dp[mask][j] == INF)
                    continue;
                for (int i = 0; i < m; i++) {
                    if (!(mask && (1 << i)))
                        continue;

                    long long travel = abs(requests[j][1] - requests[i][1]);
                    long long arrival = dp[mask][j] + travel;
                    long long newTime = max(arrival, (long long)requests[i][0]);
                    int newMask = mask | (1 << i);

                    dp[newMask][i] = min(dp[newMask][i], newTime);
                }
            }
        }
        long long ans = INF;
        int full = (1 << m) - 1;
        for (int i = 0; i < m; i++) {
            ans = min(ans, dp[full][i]);
        }
        return ans;
    }
};
