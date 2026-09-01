// 3568. Minimum Moves to Clean the Classroom
// Difficulty: Medium
// https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
// Runtime: 247 ms (beats —)
// Memory: 153.9 MB (beats —)
// Submitted: 2026-09-01

class Solution {
public:
    int minMoves(vector<string>& g, int e) {
        int n = g.size(), m = g[0].size(), sx, sy, k = 0;
        vector<vector<int>> id(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == 'S') sx = i, sy = j;
                else if (g[i][j] == 'L') id[i][j] = k++;

        if (!k) return 0;
        int all = (1 << k) - 1;

        vector vis(n, vector(m, vector<int>(1 << k, -1)));
        queue<array<int,5>> q;
        q.push({sx, sy, 0, e, 0});
        vis[sx][sy][0] = e;

        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        while (!q.empty()) {
            auto [r,c,mask,en,mv] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m || g[nr][nc] == 'X' || en == 0) continue;

                int ne = g[nr][nc] == 'R' ? e : en - 1;
                int nm = mask;
                if (g[nr][nc] == 'L') nm |= 1 << id[nr][nc];
                if (nm == all) return mv + 1;
                if (ne <= vis[nr][nc][nm]) continue;

                vis[nr][nc][nm] = ne;
                q.push({nr, nc, nm, ne, mv + 1});
            }
        }
        return -1;
    }
};
