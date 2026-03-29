// 3887. Incremental Even-Weighted Cycle Queries
// Difficulty: Hard
// https://leetcode.com/problems/incremental-even-weighted-cycle-queries/
// Runtime: 55 ms (beats —)
// Memory: 300 MB (beats —)
// Submitted: 2026-03-29

class Solution {
public:
    vector<int> parent, rankv, parity;

    int find(int x) {
        if (parent[x] != x) {
            int px = parent[x];
            parent[x] = find(parent[x]);
            parity[x] ^= parity[px];
        }
        return parent[x];
    }

    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rankv.assign(n, 0);
        parity.assign(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i;

        int ans = 0;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int pu = find(u);
            int pv = find(v);

            if (pu != pv) {
                parent[pu] = pv;
                parity[pu] = parity[u] ^ parity[v] ^ w;
                ans++;
            } else {
                int cycle = parity[u] ^ parity[v] ^ w;
                if (cycle == 0) ans++;
            }
        }

        return ans;
    }
};
