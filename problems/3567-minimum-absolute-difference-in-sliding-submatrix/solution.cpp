// 3567. Minimum Absolute Difference in Sliding Submatrix
// Difficulty: Medium
// https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/
// Runtime: 15 ms (beats —)
// Memory: 32.2 MB (beats —)
// Submitted: 2026-03-20

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> result(rows - k + 1, vector<int>(cols - k + 1, 0));

        for (int r = 0; r + k <= rows; r++) {
            for (int c = 0; c + k <= cols; c++) {

                vector<int> elements;

                for (int i = 0; i < k; i++) {
                    for (int j = 0; j < k; j++) {
                        elements.push_back(grid[r + i][c + j]);
                    }
                }

                sort(elements.begin(), elements.end());
                elements.erase(unique(elements.begin(), elements.end()),
                               elements.end());

                if (elements.size() < 2) {
                    result[r][c] = 0;
                    continue;
                }

                int minDiff = INT_MAX;
                for (int i = 1; i < elements.size(); i++) {
                    minDiff = min(minDiff, elements[i] - elements[i - 1]);
                }

                result[r][c] = minDiff;
            }
        }

        return result;
    }
};
