// 1391. Check if There is a Valid Path in a Grid
// Difficulty: Medium
// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// Runtime: 21 ms (beats —)
// Memory: 74.7 MB (beats —)
// Submitted: 2026-04-27

class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> directions = {
        {1, {{0, -1}, {0, 1}}},  {2, {{1, 0}, {-1, 0}}},
        {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}}, {6, {{0, 1}, {-1, 0}}}};

    unordered_map<int, vector<vector<int>>> valid = {
        {1, {{1, 4, 6}, {1, 3, 5}}}, {2, {{2, 5, 6}, {2, 3, 4}}},
        {3, {{1, 4, 6}, {2, 5, 6}}}, {4, {{1, 3, 5}, {2, 5, 6}}},
        {5, {{1, 4, 6}, {2, 3, 4}}}, {6, {{1, 3, 5}, {2, 3, 4}}}};

    bool dfs(int x, int y, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        int m = grid.size(), n = grid[0].size();

        if (x == m - 1 && y == n - 1)
            return true;

        vis[x][y] = 1;
        int type = grid[x][y];

        for (int i = 0; i < 2; i++) {
            int dx = directions[type][i].first;
            int dy = directions[type][i].second;

            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (vis[nx][ny])
                continue;

            int nextType = grid[nx][ny];

            for (int v : valid[type][i]) {
                if (v == nextType) {
                    if (dfs(nx, ny, grid, vis))
                        return true;
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        return dfs(0, 0, grid, vis);
    }
};
