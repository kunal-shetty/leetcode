// 835. Image Overlap
// Difficulty: Medium
// https://leetcode.com/problems/image-overlap/
// Runtime: 8 ms (beats —)
// Memory: 14 MB (beats —)
// Submitted: 2026-09-13

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> pos1, pos2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) pos1.emplace_back(i, j);
                if (img2[i][j] == 1) pos2.emplace_back(i, j);
            }
        }
        vector<vector<int>> count(2 * n, vector<int>(2 * n, 0));
        int best = 0;
        for (auto a : pos1) {
            for (auto b : pos2) {
                int dx = b.first - a.first + n;
                int dy = b.second - a.second + n;
                best = max(best, ++count[dx][dy]);
            }
        }
        return best;
    }
};
