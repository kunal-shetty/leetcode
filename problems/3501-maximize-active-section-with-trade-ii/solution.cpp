// 3501. Maximize Active Section with Trade II
// Difficulty: Hard
// https://leetcode.com/problems/maximize-active-section-with-trade-ii/
// Runtime: 210 ms (beats —)
// Memory: 260.5 MB (beats —)
// Submitted: 2026-07-22

class SegmentTree {
    vector<int> st;
    int n;

    void build(int p, int l, int r, const vector<int>& a) {
        if (l == r)
            return st[p] = a[l], void();
        int m = (l + r) / 2;
        build(p << 1, l, m, a);
        build(p << 1 | 1, m + 1, r, a);
        st[p] = max(st[p << 1], st[p << 1 | 1]);
    }

    int query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R)
            return st[p];
        int m = (l + r) / 2, res = 0;
        if (L <= m)
            res = query(p << 1, l, m, L, R);
        if (R > m)
            res = max(res, query(p << 1 | 1, m + 1, r, L, R));
        return res;
    }

public:
    SegmentTree(vector<int>& a) {
        n = a.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    int query(int l, int r) { return l > r ? 0 : query(1, 0, n - 1, l, r); }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& q) {
        int n = s.size(), ones = count(s.begin(), s.end(), '1');
        vector<int> z, L, R;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            if (s[i] == '0')
                z.push_back(j - i), L.push_back(i), R.push_back(j - 1);
            i = j;
        }

        int m = z.size();
        if (m < 2)
            return vector<int>(q.size(), ones);

        vector<int> sum(m - 1);
        for (int i = 0; i < m - 1; i++)
            sum[i] = z[i] + z[i + 1];

        SegmentTree st(sum);
        vector<int> ans;

        for (auto& x : q) {
            int l = x[0], r = x[1];
            int i = lower_bound(R.begin(), R.end(), l) - R.begin();
            int j = upper_bound(L.begin(), L.end(), r) - L.begin() - 1;

            if (i >= j || i >= m || j < 0) {
                ans.push_back(ones);
                continue;
            }

            int a = R[i] - max(L[i], l) + 1;
            int b = min(R[j], r) - L[j] + 1;

            if (i + 1 == j) {
                ans.push_back(ones + a + b);
                continue;
            }

            ans.push_back(ones + max({a + z[i + 1], z[j - 1] + b,
                                      st.query(i + 1, j - 2)}));
        }
        return ans;
    }
};
