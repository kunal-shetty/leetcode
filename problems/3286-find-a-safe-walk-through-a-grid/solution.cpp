// 3286. Find a Safe Walk Through a Grid
// Difficulty: Medium
// https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
// Runtime: 11 ms (beats —)
// Memory: 31.7 MB (beats —)
// Submitted: 2026-07-02

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        health -= grid[0][0];
        if (health < 1)
            return false;

        int rows = grid.size(), cols = grid[0].size();
        priority_queue<tuple<int, int, int>> pq;
        vector<vector<int>> best(rows, vector<int>(cols, 0));

        pq.push({health, 0, 0});
        best[0][0] = health;

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto [currHealth, row, col] = pq.top();
            pq.pop();

            for (auto dir : dirs) {
                int newRow = row + dir[0], newCol = col + dir[1];
                if (newRow < 0 || newCol < 0 || newRow >= rows ||
                    newCol >= cols)
                    continue;

                int nextHealth = currHealth - grid[newRow][newCol];
                if (nextHealth < 1 || nextHealth <= best[newRow][newCol])
                    continue;

                if (newRow == rows - 1 && newCol == cols - 1)
                    return true;

                best[newRow][newCol] = nextHealth;
                pq.push({nextHealth, newRow, newCol});
            }
        }

        return rows == 1 && cols == 1;
    }
};
