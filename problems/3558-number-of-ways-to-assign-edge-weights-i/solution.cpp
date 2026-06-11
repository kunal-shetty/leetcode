// 3558. Number of Ways to Assign Edge Weights I
// Difficulty: Medium
// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/
// Runtime: 447 ms (beats —)
// Memory: 367.1 MB (beats —)
// Submitted: 2026-06-11

class Solution {
public:
    int MOD = 1e9 + 7;
    int dfs(vector<vector<int>>& adj, int i, int parent) {
        int depth = 0;
        for (auto node : adj[i]) {
            if (node == parent)
                continue;
            depth = max(depth, dfs(adj, node, i) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int depth = dfs(adj, 1, 0) - 1;

        long long ans = 1;
        while (depth--) {
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
};
