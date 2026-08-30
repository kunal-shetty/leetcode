// 4041. Minimum Operations to Form Subset Sum II
// Difficulty: Hard
// https://leetcode.com/problems/minimum-operations-to-form-subset-sum-ii/
// Runtime: 565 ms (beats —)
// Memory: 101.7 MB (beats —)
// Submitted: 2026-08-30

class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        int l = max(sum, *max_element(nums.begin(), nums.end()));
        for (auto num : nums) {
            vector<int> dist(l + 1, INF);
            queue<int> q;
            dist[num] = 0;
            q.push(num);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                int h = v / 2;
                if (dist[h] == INF) {
                    dist[h] = dist[v] + 1;
                    q.push(h);
                }

                if (v * 2 <= sum && dist[v * 2] == INF) {
                    dist[v * 2] = dist[v] + 1;
                    q.push(v * 2);
                }
            }
            vector<pair<int, int>> vals;
            for (int i = 0; i <= sum; i++) {
                if (dist[i] != INF) {
                    vals.push_back({i, dist[i]});
                }
            }
            vector<int> ndp = dp;
            for (int i = 0; i <= sum; i++) {
                if (dp[i] == INF)
                    continue;
                for (auto [v, c] : vals) {
                    if (i + v <= sum) {
                        ndp[i + v] = min(ndp[i + v], dp[i] + c);
                    }
                }
            }
            dp.swap(ndp);
        }
        return dp[sum] == INF ? -1 : dp[sum];
    }
};
