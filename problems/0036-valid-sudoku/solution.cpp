// 36. Valid Sudoku
// Difficulty: Medium
// https://leetcode.com/problems/valid-sudoku/
// Runtime: 2 ms (beats —)
// Memory: 24.4 MB (beats —)
// Submitted: 2026-09-02

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> r, c, box;
            for (int j = 0; j < 9; j++) {
                if (b[i][j] != '.' && !r.insert(b[i][j]).second) return false;
                if (b[j][i] != '.' && !c.insert(b[j][i]).second) return false;

                int x = (i / 3) * 3 + j / 3;
                int y = (i % 3) * 3 + j % 3;
                if (b[x][y] != '.' && !box.insert(b[x][y]).second) return false;
            }
        }
        return true;
    }
};
