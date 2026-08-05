// 3310. Remove Methods From Project
// Difficulty: Medium
// https://leetcode.com/problems/remove-methods-from-project/
// Runtime: 501 ms (beats —)
// Memory: 389.1 MB (beats —)
// Submitted: 2026-08-05

class Solution {
public:
    bool dfs(int u, vector<vector<int>> &g, vector<bool> &vis,
             vector<bool> &sus, bool check = false) {

        vis[u] = true;

        for (int v : g[u]) {
            if (check && !sus[v]) return false;
            if (!vis[v] && !dfs(v, g, vis, sus, check))
                return false;
        }

        return true;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n), rev(n);

        for (auto e : invocations) {
            adj[e[0]].push_back(e[1]);
            rev[e[1]].push_back(e[0]);
        }

        vector<bool> sus(n), vis(n);
        dfs(k, adj, sus, sus);

        bool ok = true;
        for (int i = 0; i < n && ok; i++)
            if (sus[i] && !vis[i])
                ok = dfs(i, rev, vis, sus, true);

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!ok || !sus[i]) ans.push_back(i);

        return ans;
    }
};
