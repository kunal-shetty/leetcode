// 2906. Construct Product Matrix
// Difficulty: Medium
// https://leetcode.com/problems/construct-product-matrix/
// Runtime: 24 ms (beats —)
// Memory: 131.8 MB (beats —)
// Submitted: 2026-03-24

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        vector<vector<int>> result(n, vector<int>(m));

        long long prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = prefix;
                prefix = (prefix * grid[i][j]) % mod;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                result[i][j] = (result[i][j] * suffix) % mod;
                suffix = (suffix * grid[i][j]) % mod;
            }
        }
        return result;
    }
};
