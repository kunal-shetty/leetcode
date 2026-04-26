// 1559. Detect Cycles in 2D Grid
// Difficulty: Medium
// https://leetcode.com/problems/detect-cycles-in-2d-grid/
// Runtime: 27 ms (beats —)
// Memory: 72.9 MB (beats —)
// Submitted: 2026-04-26

class Solution {
public:
    int m, n;
    vector<vector<int>> vis;
    
    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        vis[x][y] = 1;
        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (grid[nx][ny] != grid[x][y]) continue;
            
            if (vis[nx][ny] == 0) {
                if (dfs(nx, ny, x, y, grid)) return true;
            } 
            else if (nx != px || ny != py) {
                return true;
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>> grid) {
        m = grid.size();
        n = grid[0].size();
        
        vis = vector<vector<int>>(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    if (dfs(i, j, -1, -1, grid)) return true;
                }
            }
        }
        return false;
    }
};
