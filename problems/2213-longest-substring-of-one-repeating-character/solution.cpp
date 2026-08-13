// 2213. Longest Substring of One Repeating Character
// Difficulty: Hard
// https://leetcode.com/problems/longest-substring-of-one-repeating-character/
// Runtime: 345 ms (beats —)
// Memory: 112.9 MB (beats —)
// Submitted: 2026-08-13

class Solution {
    struct Node {
        int len = 0, pref = 0, suff = 0, best = 0;
        char lc = 0, rc = 0;
    };
    vector<Node> st;
    int n;

    Node merge(Node a, Node b) {
        if (!a.len)
            return b;
        if (!b.len)
            return a;
        Node r;
        r.len = a.len + b.len;
        r.lc = a.lc;
        r.rc = b.rc;
        r.pref = (a.pref == a.len && a.rc == b.lc) ? a.len + b.pref : a.pref;
        r.suff = (b.suff == b.len && a.rc == b.lc) ? b.len + a.suff : b.suff;
        r.best = max(a.best, b.best);
        if (a.rc == b.lc)
            r.best = max(r.best, a.suff + b.pref);
        return r;
    }

    void build(int p, int l, int r, string& s) {
        if (l == r) {
            st[p] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }
        int m = (l + r) / 2;
        build(p << 1, l, m, s);
        build(p << 1 | 1, m + 1, r, s);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

    void update(int p, int l, int r, int i, char c) {
        if (l == r) {
            st[p] = {1, 1, 1, 1, c, c};
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            update(p << 1, l, m, i, c);
        else
            update(p << 1 | 1, m + 1, r, i, c);
        st[p] = merge(st[p << 1], st[p << 1 | 1]);
    }

public:
    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        n = s.size();
        st.resize(4 * n);
        build(1, 0, n - 1, s);

        vector<int> ans;
        for (int i = 0; i < qi.size(); i++) {
            update(1, 0, n - 1, qi[i], qc[i]);
            ans.push_back(st[1].best);
        }
        return ans;
    }
};
