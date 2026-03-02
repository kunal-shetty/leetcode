// 1536. Minimum Swaps to Arrange a Binary Grid
// Difficulty: Medium
// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
// Runtime: 0 ms (beats —)
// Memory: 29.6 MB (beats —)
// Submitted: 2026-03-02

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> z;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--)
                count++;
            z.push_back(count);
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int re = n - i - 1, j = i;
            while (j < n && z[j] < re) j++;
            if (j == n) return -1;

            swaps += j - i;
            while (j > i)
                swap(z[j], z[--j]);
        }

        return swaps;
    }
};
