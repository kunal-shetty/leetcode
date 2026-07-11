// 2685. Count the Number of Complete Components
// Difficulty: Medium
// https://leetcode.com/problems/count-the-number-of-complete-components/
// Runtime: 69 ms (beats —)
// Memory: 131 MB (beats —)
// Submitted: 2026-07-11

class Solution {
public:
    int find(int i, vector<int>& root) {
        if (root[i] == i)
            return i;
        return root[i] = find(root[i], root);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> root(n);
        iota(root.begin(), root.end(), 0);

        for (auto e : edges)
            root[find(e[0], root)] = find(e[1], root);

        vector<int> V(n, 0);
        vector<int> E(n, 0);

        for (int i = 0; i < n; i++)
            V[find(i, root)]++;

        for (auto e : edges)
            E[find(e[0], root)]++;

        int res = 0;

        for (int i = 0; i < n; i++)
            if (V[i] && E[i] == V[i] * (V[i] - 1) / 2)
                res++;

        return res;
    }
};
