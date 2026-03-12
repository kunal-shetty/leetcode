// 3600. Maximize Spanning Tree Stability with Upgrades
// Difficulty: Hard
// https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/
// Runtime: 55 ms (beats —)
// Memory: 220.2 MB (beats —)
// Submitted: 2026-03-12

class Solution {
public:
    int find(int v, vector<int>& parent) {
        if (parent[v] != v)
            parent[v] = find(parent[v], parent);
        return parent[v];
    }

    bool unionSets(int a, int b, vector<int>& parent, vector<int>& size) {
        a = find(a, parent);
        b = find(b, parent);

        if (a == b) return false;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<int> parent(n), size(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int comp = n;
        int res = INT_MAX;
        vector<int> opt;

        for (int i = 0; i < edges.size(); i++) {
            vector<int>& e = edges[i];
            if (e[3] == 1) {
                if (!unionSets(e[0], e[1], parent, size))
                    return -1;

                comp--;
                res = min(res, e[2]);
            }
        }

        if (comp == 1) return res;

        for (int i = 0; i < edges.size(); i++)
            if (edges[i][3] == 0)
                opt.push_back(i);

        sort(opt.begin(), opt.end(), [&](int a, int b) {
            return edges[a][2] > edges[b][2];
        });

        vector<int> stab;

        for (int i = 0; i < opt.size(); i++) {
            int idx = opt[i];
            vector<int>& e = edges[idx];

            if (unionSets(e[0], e[1], parent, size)) {
                comp--;
                stab.push_back(e[2]);
                if (comp == 1) break;
            }
        }

        if (comp > 1) return -1;

        for (int i = 1; i <= min((int)stab.size(), k); i++)
            stab[stab.size() - i] *= 2;

        return min(res, *min_element(stab.begin(), stab.end()));
    }
};
