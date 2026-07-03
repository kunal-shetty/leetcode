// 3620. Network Recovery Pathways
// Difficulty: Hard
// https://leetcode.com/problems/network-recovery-pathways/
// Runtime: 199 ms (beats —)
// Memory: 303 MB (beats —)
// Submitted: 2026-07-03

class Solution {
public:
    bool check(vector<vector<pair<int, int>>>& g, int n, int mid, long long k) {
        vector<long long> dis(n, LLONG_MAX);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;

        dis[0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();

            if (d > k)
                return false;

            if (u == n - 1)
                return true;

            if (d > dis[u])
                continue;

            for (auto& [v, w] : g[u]) {
                if (w < mid)
                    continue;

                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({dis[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> g(n);

        int l = INT_MAX, r = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (!online[u] || !online[v])
                continue;

            g[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }

        if (!check(g, n, l, k))
            return -1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (check(g, n, mid, k))
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
};
