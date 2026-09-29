// 2267.  Check if There Is a Valid Parentheses String Path
// Difficulty: Hard
// https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
// Runtime: 160 ms (beats —)
// Memory: 82.8 MB (beats —)
// Submitted: 2026-09-29

class Solution {
public:
    using T = tuple<int, int, int>;

    bool hasValidPath(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        if ((r + c) % 2 == 0)
            return false;

        if (grid[0][0] == ')' || grid[r - 1][c - 1] == '(')
            return false;

        queue<T> q;
        q.push({0, 0, 1});

        vector<vector<vector<bool>>> visited(
            r, vector<vector<bool>>(c, vector<bool>(r + c, false))
        );

        visited[0][0][1] = true;

        while (!q.empty()) {
            auto [i, j, bal] = q.front();
            q.pop();

            if (bal < 0)
                continue;

            if (i == r - 1 && j == c - 1 && bal == 0)
                return true;

            if (i + 1 < r) {
                int newBal = bal + (grid[i + 1][j] == '(' ? 1 : -1);

                if (newBal >= 0 && !visited[i + 1][j][newBal]) {
                    visited[i + 1][j][newBal] = true;
                    q.push({i + 1, j, newBal});
                }
            }

            if (j + 1 < c) {
                int newBal = bal + (grid[i][j + 1] == '(' ? 1 : -1);

                if (newBal >= 0 && !visited[i][j + 1][newBal]) {
                    visited[i][j + 1][newBal] = true;
                    q.push({i, j + 1, newBal});
                }
            }
        }

        return false;
    }
};
