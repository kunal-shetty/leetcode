// 1260. Shift 2D Grid
// Difficulty: Easy
// https://leetcode.com/problems/shift-2d-grid/
// Runtime: 0 ms (beats —)
// Memory: 18.2 MB (beats —)
// Submitted: 2026-07-20

class Solution {
public:
    void shift(vector<vector<int>>& grid, int c, int i, int j) {
        while (i < j) {
            swap(grid[i / c][i % c], grid[j / c][j % c]);
            i++;
            j--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if (!k)
            return grid;

        int r = grid.size();
        int c = grid[0].size();
        int n = r * c;

        k %= n;
        if (!k)
            return grid;

        shift(grid, c, 0, n - 1);
        shift(grid, c, 0, k - 1);
        shift(grid, c, k, n - 1);

        return grid;
    }
};
