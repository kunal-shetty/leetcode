// 37. Sudoku Solver
// Difficulty: Hard
// https://leetcode.com/problems/sudoku-solver/
// Runtime: 400 ms (beats —)
// Memory: 8.9 MB (beats —)
// Submitted: 2026-01-19

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            // row check
            if (board[row][i] == num) return false;

            // column check
            if (board[i][col] == num) return false;

            // 3x3 box check
            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;
            if (board[r][c] == num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;

                            if (solve(board)) return true;

                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
