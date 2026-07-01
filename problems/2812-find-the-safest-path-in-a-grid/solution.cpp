// 2812. Find the Safest Path in a Grid
// Difficulty: Medium
// https://leetcode.com/problems/find-the-safest-path-in-a-grid/
// Runtime: 346 ms (beats —)
// Memory: 137.8 MB (beats —)
// Submitted: 2026-07-01

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, -1));
        queue<pair<int, int>> bfsQueue;
        int dir[5] = {0, 1, 0, -1, 0};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    bfsQueue.push({i, j}), distance[i][j] = 0;

        while (!bfsQueue.empty()) {
            auto [x, y] = bfsQueue.front();
            bfsQueue.pop();

            for (int k = 0; k < 4; k++) {
                int newX = x + dir[k];
                int newY = y + dir[k + 1];

                if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
                    distance[newX][newY] == -1) {
                    distance[newX][newY] = distance[x][y] + 1;
                    bfsQueue.push({newX, newY});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<int>> visited(n, vector<int>(n));
        maxHeap.push({distance[0][0], {0, 0}});

        while (!maxHeap.empty()) {
            auto [safeness, cell] = maxHeap.top();
            maxHeap.pop();

            auto [x, y] = cell;
            if (visited[x][y])
                continue;
            visited[x][y] = 1;

            if (x == n - 1 && y == n - 1)
                return safeness;

            for (int k = 0; k < 4; k++) {
                int newX = x + dir[k];
                int newY = y + dir[k + 1];

                if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
                    !visited[newX][newY]) {
                    maxHeap.push(
                        {min(safeness, distance[newX][newY]), {newX, newY}});
                }
            }
        }

        return -1;
    }
};
