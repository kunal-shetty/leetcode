// 1140. Stone Game II
// Difficulty: Medium
// https://leetcode.com/problems/stone-game-ii/
// Runtime: 4 ms (beats —)
// Memory: 13.8 MB (beats —)
// Submitted: 2026-08-09

class Solution {
public:
    vector<vector<int>> out;
    vector<int> st;

    int solve(int i, int m, vector<int>& piles) {
        int n = piles.size();
        if (i >= n)
            return 0;

        if (2 * m >= n - i)
            return st[i];

        if (out[i][m] != -1)
            return out[i][m];

        int ans = 0;

        for (int x = 1; x <= min(2 * m, n - i); x++) {
            ans = max(ans,
                      st[i] - solve(i + x, max(m, x), piles));
        }

        return out[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        st.resize(n);
        st[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--)
            st[i] = st[i + 1] + piles[i];

        out.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles);
    }
};
