// 1975. Maximum Matrix Sum
// Difficulty: Medium
// https://leetcode.com/problems/maximum-matrix-sum/
// Runtime: 0 ms (beats —)
// Memory: 39.2 MB (beats —)
// Submitted: 2026-01-05

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        long long smallest = LLONG_MAX;
        int negCount = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < 0) {
                    negCount++;
                }

                long long val = llabs(matrix[i][j]);
                sum += val;
                smallest = min(smallest, val);
            }
        }

        if (negCount % 2 == 1) {
            sum -= 2 * smallest;
        }

        return sum;
    }
};
