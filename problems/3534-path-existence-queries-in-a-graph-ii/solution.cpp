// 3534. Path Existence Queries in a Graph II
// Difficulty: Hard
// https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/
// Runtime: 240 ms (beats —)
// Memory: 349.4 MB (beats —)
// Submitted: 2026-07-10

class Solution {
public:
    static constexpr int LOG = 17;

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {
        vector<pair<int, int>> order;
        order.reserve(n);

        for (int i = 0; i < n; ++i)
            order.emplace_back(nums[i], i);

        sort(order.begin(), order.end());

        vector<array<int, LOG>> up(n);

        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            while (order[r].first - order[l].first > maxDiff)
                --r;

            int u = order[l].second;
            up[u][0] = order[r].second;

            for (int k = 1; k < LOG; ++k)
                up[u][k] = up[up[u][k - 1]][k - 1];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto q : queries) {
            int u = q[0];
            int v = q[1];

            if (nums[u] > nums[v])
                swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int target = nums[v];
            int step = 0;

            for (int k = LOG - 1; k >= 0; --k) {
                int next = up[u][k];
                if (nums[next] < target) {
                    u = next;
                    step += 1 << k;
                }
            }

            ans.push_back(nums[up[u][0]] < target ? -1 : step + 1);
        }

        return ans;
    }
};
