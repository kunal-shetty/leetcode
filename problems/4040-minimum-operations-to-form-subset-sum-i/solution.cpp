// 4040. Minimum Operations to Form Subset Sum I
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-form-subset-sum-i/
// Runtime: 212 ms (beats —)
// Memory: 72.2 MB (beats —)
// Submitted: 2026-08-30

class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1e9;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        int l = max(sum, *max_element(nums.begin(), nums.end()));
        for (auto num : nums) {
            unordered_map<int, int> best;
            int v = num, c = 0;
            while (v <= sum) {
                if (!best.count(v) || best[v] > c)
                    best[v] = c;
                if (v > sum / 2)
                    break;
                v *= 2;
                c++;
            }
            // diviiede
            v = num;
            c = 0;
            while (7) {
                if (v > 0 && v <= sum) {
                    if (!best.count(v) || best[v] > c)
                        best[v] = c;
                }
                if (v == 0)
                    break;
                v /= 2;
                c++;
            }

            vector<int> ndp = dp;
            for (int i = 0; i <= sum; i++) {
                if (dp[i] == INF)
                    continue;
                for (auto [v, c] : best) {
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
