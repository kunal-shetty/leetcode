// 4085. Find Root of a Colored Tree
// Difficulty: Medium
// https://leetcode.com/problems/find-root-of-a-colored-tree/
// Runtime: 141 ms (beats 52.5%)
// Memory: 266 MB (beats 53.3%)
// Submitted: 2026-10-18

class Solution {
public:
    int colorId(char c) {
        if (c == 'R') return 0;
        else if (c == 'B') return 1;
        return 2;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> indegree(n, 0), outdegree(n, 0);

        for (auto e : edges) {
            int u = e[0], v = e[1];
            int cu = colorId(colors[u]), cv = colorId(colors[v]);

            if (cu == cv) return -1;

            if ((cu + 1) % 3 == cv) {
                outdegree[u]++;
                indegree[v]++;
            } else {
                outdegree[v]++;
                indegree[u]++;
            }
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (outdegree[i] > 2) return -1;

            if (indegree[i] == 0) {
                if (root != -1) return -1;
                root = i;
            } else if (indegree[i] != 1) return -1;
        }
        return root;
    }
};
