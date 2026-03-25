// 3546. Equal Sum Grid Partition I
// Difficulty: Medium
// https://leetcode.com/problems/equal-sum-grid-partition-i/
// Runtime: 3 ms (beats —)
// Memory: 126.3 MB (beats —)
// Submitted: 2026-03-25

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        
        if (total % 2) return false;
        
        long long target = total / 2, sum = 0;
        
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }
        
        sum = 0;
        
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }
        
        return false;
    }
};
