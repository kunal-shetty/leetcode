// 51. N-Queens
// Difficulty: Hard
// https://leetcode.com/problems/n-queens/
// Runtime: 0 ms (beats —)
// Memory: 10.2 MB (beats —)
// Submitted: 2026-08-06

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false), d1(2 * n, false), d2(2 * n, false);
        vector<int> pos(n, -1);

        int r = 0;

        while (r >= 0) {
            if (pos[r] != -1) {
                int c = pos[r];
                board[r][c] = '.';
                col[c] = d1[r + c] = d2[r - c + n] = false;
            }

            pos[r]++;

            while (pos[r] < n &&
                  (col[pos[r]] || d1[r + pos[r]] || d2[r - pos[r] + n]))
                pos[r]++;

            if (pos[r] == n) {
                pos[r] = -1;
                r--;
            } else {
                int c = pos[r];
                board[r][c] = 'Q';
                col[c] = d1[r + c] = d2[r - c + n] = true;

                if (r == n - 1) {
                    ans.push_back(board);
                } else {
                    r++;
                    pos[r] = -1;
                }
            }
        }

        return ans;
    }
};
