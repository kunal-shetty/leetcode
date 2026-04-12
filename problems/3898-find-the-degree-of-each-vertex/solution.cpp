// 3898. Find the Degree of Each Vertex
// Difficulty: Easy
// https://leetcode.com/problems/find-the-degree-of-each-vertex/
// Runtime: 3 ms (beats —)
// Memory: 54.2 MB (beats —)
// Submitted: 2026-04-12

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int degree = 0;
            for (int j = 0; j < n; j++) {
                degree += matrix[i][j];
            }
            ans[i] = degree;
        }

        return ans;
    }
};
