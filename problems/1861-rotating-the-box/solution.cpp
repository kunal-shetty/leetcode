// 1861. Rotating the Box
// Difficulty: Medium
// https://leetcode.com/problems/rotating-the-box/
// Runtime: 16 ms (beats —)
// Memory: 56.7 MB (beats —)
// Submitted: 2026-05-06

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++) {
            int empty = n - 1;

            for (int j = n - 1; j >= 0; j--) {

                if (boxGrid[i][j] == '*') {
                    empty = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        vector<vector<char>> rotated(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[i][j] = boxGrid[m - 1 - j][i];
            }
        }

        return rotated;
    }
};
