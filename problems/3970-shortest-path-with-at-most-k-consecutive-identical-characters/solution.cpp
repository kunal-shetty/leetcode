// 3970. Shortest Path With At Most K Consecutive Identical Characters
// Difficulty: Medium
// https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
// Runtime: 333 ms (beats —)
// Memory: 330.5 MB (beats —)
// Submitted: 2026-06-21

using T = tuple<long long, int, int>;
const long long INF = 1e18;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, count] = pq.top();
            pq.pop();

            if (d > dist[u][count])
                continue;

            for (auto [v, w] : g[u]) {
                int newCount = labels[u] == labels[v] ? count + 1 : 1;
                if (newCount > k)
                    continue;

                if (d + w < dist[v][newCount]) {
                    dist[v][newCount] = d + w;
                    pq.push({d + w, v, newCount});
                }
            }
        }
        long long ans =
            *min_element(dist[n - 1].begin() + 1, dist[n - 1].end());
        return ans == INF ? -1 : ans;
    }
};
