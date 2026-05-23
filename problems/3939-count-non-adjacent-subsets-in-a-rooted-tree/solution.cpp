// 3939. Count Non Adjacent Subsets in a Rooted Tree
// Difficulty: Hard
// https://leetcode.com/problems/count-non-adjacent-subsets-in-a-rooted-tree/
// Runtime: 882 ms (beats —)
// Memory: 121.3 MB (beats —)
// Submitted: 2026-05-23

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> g;
    int K;

    pair<vector<long long>, vector<long long>> dfs(int u, vector<int>& nums) {
        vector<long long> take(K, 0), skip(K, 0);
        skip[0] = 1;
        take[nums[u] % K] = 1;

        for (int v : g[u]) {
            auto [childSkip, childTake] = dfs(v, nums);
            vector<long long> best(K);

            for (int i = 0; i < K; i++) {
                best[i] = (childSkip[i] + childTake[i]) % MOD;
            }
            vector<long long> newTake(K, 0), newSkip(K, 0);
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < K; j++) {
                    newSkip[(i + j) % K] =
                        (newSkip[(i + j) % K] + skip[i] * best[j]) % MOD;
                    newTake[(i + j) % K] =
                        (newTake[(i + j) % K] + take[i] * childSkip[j]) % MOD;
                }
            }
            skip = newSkip;
            take = newTake;
        }
        return {skip, take};
    }

    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = parent.size();
        K = k;
        g.resize(n);

        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }

        auto [skip, take] = dfs(0, nums);

        long long ans = (skip[0] + take[0] - 1 + MOD) % MOD;
        return ans;
    }
};
