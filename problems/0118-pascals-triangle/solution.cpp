// 118. Pascal's Triangle
// Difficulty: Easy
// https://leetcode.com/problems/pascals-triangle/
// Runtime: 2 ms (beats —)
// Memory: 9.7 MB (beats —)
// Submitted: 2026-04-04

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};
