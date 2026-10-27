// 3963. Create Grid With Exactly One Path
// Difficulty: Easy
// https://leetcode.com/problems/create-grid-with-exactly-one-path/
// Runtime: 0 ms (beats 100.0%)
// Memory: 11 MB (beats 74.2%)
// Submitted: 2026-10-27

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        for(int i = 0; i < n; i ++){
            grid[0][i] = '.';
        }
        for(int i = 0; i <m; i ++){
            grid[i][n -1] = '.';
        }
        return grid;
    }
};
