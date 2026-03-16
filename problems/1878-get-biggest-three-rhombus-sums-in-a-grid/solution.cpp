// 1878. Get Biggest Three Rhombus Sums in a Grid
// Difficulty: Medium
// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
// Runtime: 219 ms (beats —)
// Memory: 65.6 MB (beats —)
// Submitted: 2026-03-16

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        int dx[4] = {1, 1, -1, -1};
        int dy[4] = {1, -1, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                st.insert(grid[i][j]);

                for (int k = 1;; k++) {
                    if (i + 2 * k >= m || j - k < 0 || j + k >= n)
                        break;

                    int x = i, y = j, sum = 0;

                    for (int d = 0; d < 4; d++) {
                        for (int t = 0; t < k; t++) {
                            sum += grid[x][y];
                            x += dx[d];
                            y += dy[d];
                        }
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> rhombus(st.begin(), st.end());
        vector<int> ans;

        for (int i = rhombus.size() - 1; i >= 0 && ans.size() < 3; i--) {
            ans.push_back(rhombus[i]);
        }

        return ans;
    }
};
