// 3619. Count Islands With Total Value Divisible by K
// Difficulty: Medium
// https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
// Runtime: 31 ms (beats 69.4%)
// Memory: 78.4 MB (beats 90.2%)
// Submitted: 2026-10-26

class Solution {
public:
    long long dfs(vector<vector<int>>& g, int i, int j) {
        int m = g.size(), n = g[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || !g[i][j])
            return 0;

        long long s = g[i][j];
        g[i][j] = 0;

        s += dfs(g, i + 1, j) + dfs(g, i - 1, j);
        s += dfs(g, i, j + 1) + dfs(g, i, j - 1);

        return s;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0, m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] && dfs(grid, i, j) % k == 0)
                    res++;

        return res;
    }
};
