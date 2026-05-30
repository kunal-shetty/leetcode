// 3161. Block Placement Queries
// Difficulty: Hard
// https://leetcode.com/problems/block-placement-queries/
// Runtime: 670 ms (beats —)
// Memory: 364.5 MB (beats —)
// Submitted: 2026-05-30

class Solution {
public:
    vector<int> seg;
    const int MX = 50000;
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid) update(node << 1, l, mid, idx, val);
        else update(node << 1 | 1, mid + 1, r, idx, val);

        seg[node] = max(seg[node << 1], seg[node << 1 | 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return seg[node];

        int mid = (l + r) >> 1;

        return max(
            query(node << 1, l, mid, ql, qr),
            query(node << 1 | 1, mid + 1, r, ql, qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        seg.assign(4 * (MX + 1), 0);

        set<int> obs = {0};

        for (auto& q : queries)
            if (q[0] == 1) obs.insert(q[1]);

        vector<int> pos(obs.begin(), obs.end());

        for (int i = 1; i < pos.size(); i++)
            update(1, 0, MX, pos[i], pos[i] - pos[i - 1]);

        vector<bool> ans;

        for (int i = queries.size() - 1; i >= 0; i--) {
            auto& q = queries[i];

            if (q[0] == 2) {
                int x = q[1], sz = q[2];

                int p = *prev(obs.upper_bound(x));

                int best = max(
                    query(1, 0, MX, 0, p),
                    x - p
                );

                ans.push_back(best >= sz);
            } else {
                int x = q[1];

                auto it = obs.find(x);
                int l = *prev(it);

                update(1, 0, MX, x, 0);

                auto rIt = next(it);

                if (rIt != obs.end()) {
                    int r = *rIt;
                    update(1, 0, MX, r, r - l);
                }

                obs.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
