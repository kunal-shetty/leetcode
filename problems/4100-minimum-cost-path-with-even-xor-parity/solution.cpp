// 4100. Minimum Cost Path With Even XOR Parity
// Difficulty: Hard
// https://leetcode.com/problems/minimum-cost-path-with-even-xor-parity/
// Runtime: 124 ms (beats 87.5%)
// Memory: 305.7 MB (beats 87.5%)
// Submitted: 2026-11-01

class Solution {
public:
    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {
        const long long INF = 1e18;
        long long res = INF;
        int n = values.size();
        vector<long long> best(n, INF);

        for (auto e : edges) {
            int u = e[0], v = e[1];
            long long w = e[2];
            int pathU = __builtin_parity(values[u]);
            int pathV = __builtin_parity(values[v]);

            if (pathU == pathV) {
                res = min(res, w);
            } else {
                int zero = (pathU == 0) ? u : v;
                res = min(res, best[zero] + w);
                best[zero] = min(best[zero], w);
            }
        }

        return res >= INF ? -1 : res;
    }
};
