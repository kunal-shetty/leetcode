// 3548. Equal Sum Grid Partition II
// Difficulty: Hard
// https://leetcode.com/problems/equal-sum-grid-partition-ii/
// Runtime: 1416 ms (beats —)
// Memory: 510.9 MB (beats —)
// Submitted: 2026-03-26

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<long long>> prefix(rows + 1, vector<long long>(cols + 1, 0));

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                prefix[i][j] = (long long)grid[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        unordered_map<long long, vector<vector<int>>> valuePositions;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                vector<int> pos(2);
                pos[0] = i;
                pos[1] = j;
                valuePositions[grid[i][j]].push_back(pos);
            }
        }

        for (int cutRow = 1; cutRow < rows; cutRow++) {
            long long topSum = prefix[cutRow][cols];
            long long bottomSum = prefix[rows][cols] - topSum;

            if (topSum == bottomSum) return true;

            long long diff = llabs(topSum - bottomSum);
            if (valuePositions.find(diff) == valuePositions.end()) continue;

            vector<vector<int>> &positions = valuePositions[diff];

            if (topSum > bottomSum) {
                for (int k = 0; k < positions.size(); k++) {
                    int i = positions[k][0];
                    int j = positions[k][1];

                    if (i < cutRow) {
                        int r = cutRow, c = cols;
                        if ((r > 1 && c > 1) ||
                            (r == 1 && (j == 0 || j == c - 1)) ||
                            (c == 1 && (i == 0 || i == r - 1)))
                            return true;
                    }
                }
            } else {
                for (int k = 0; k < positions.size(); k++) {
                    int i = positions[k][0];
                    int j = positions[k][1];

                    if (i >= cutRow) {
                        int r = rows - cutRow, c = cols;
                        if ((r > 1 && c > 1) ||
                            (r == 1 && (j == 0 || j == c - 1)) ||
                            (c == 1 && (i == cutRow || i == rows - 1)))
                            return true;
                    }
                }
            }
        }

        for (int cutCol = 1; cutCol < cols; cutCol++) {
            long long leftSum = prefix[rows][cutCol];
            long long rightSum = prefix[rows][cols] - leftSum;

            if (leftSum == rightSum) return true;

            long long diff = llabs(leftSum - rightSum);
            if (valuePositions.find(diff) == valuePositions.end()) continue;

            vector<vector<int>> &positions = valuePositions[diff];

            if (leftSum > rightSum) {
                for (int k = 0; k < positions.size(); k++) {
                    int i = positions[k][0];
                    int j = positions[k][1];

                    if (j < cutCol) {
                        int r = rows, c = cutCol;
                        if ((r > 1 && c > 1) ||
                            (r == 1 && (j == 0 || j == c - 1)) ||
                            (c == 1 && (i == 0 || i == r - 1)))
                            return true;
                    }
                }
            } else {
                for (int k = 0; k < positions.size(); k++) {
                    int i = positions[k][0];
                    int j = positions[k][1];

                    if (j >= cutCol) {
                        int r = rows, c = cols - cutCol;
                        if ((r > 1 && c > 1) ||
                            (r == 1 && (j == cutCol || j == cols - 1)) ||
                            (c == 1 && (i == 0 || i == r - 1)))
                            return true;
                    }
                }
            }
        }

        return false;
    }
};
