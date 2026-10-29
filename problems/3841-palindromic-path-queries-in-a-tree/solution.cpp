// 3841. Palindromic Path Queries in a Tree
// Difficulty: Hard
// https://leetcode.com/problems/palindromic-path-queries-in-a-tree/
// Runtime: 701 ms (beats 31.8%)
// Memory: 427.5 MB (beats 11.4%)
// Submitted: 2026-10-29

class Solution {
    int n, logN, timer;
    vector<vector<int>> adj, ancestors;
    vector<int> entry, exit, charMask, prefixMask, fenwick;

    void add(int index, int value) {
        index++;

        while (index <= n) {
            fenwick[index] ^= value;
            index += index & -index;
        }
    }

    int get(int index) {
        int result = 0;
        index++;

        while (index > 0) {
            result ^= fenwick[index];
            index -= index & -index;
        }

        return result;
    }

    void update(int node, char newChar) {
        int oldMask = charMask[node];
        int newMask = 1 << (newChar - 'a');
        int change = oldMask ^ newMask;

        add(entry[node], change);

        if (exit[node] + 1 < n)
            add(exit[node] + 1, change);

        charMask[node] = newMask;
    }

    bool isAncestor(int node, int other) {
        return entry[node] <= entry[other] && exit[other] <= exit[node];
    }

    int lca(int nodeA, int nodeB) {
        if (isAncestor(nodeA, nodeB))
            return nodeA;
        if (isAncestor(nodeB, nodeA))
            return nodeB;

        for (int level = logN - 1; level >= 0; level--)
            if (!isAncestor(ancestors[level][nodeA], nodeB))
                nodeA = ancestors[level][nodeA];

        return ancestors[0][nodeA];
    }

    bool check(int nodeA, int nodeB) {
        int common = lca(nodeA, nodeB);

        int path = (prefixMask[nodeA] ^ get(entry[nodeA])) ^
                   (prefixMask[nodeB] ^ get(entry[nodeB])) ^ charMask[common];

        return !(path & (path - 1));
    }

    void dfs() {
        vector<vector<int>> stack = {{0, 0, 0}};
        while (!stack.empty()) {
            auto curr = stack.back();
            stack.pop_back();

            int node = curr[0], parent = curr[1], state = curr[2];
            if (state == 1) {
                exit[node] = timer - 1;
                continue;
            }

            entry[node] = timer++;
            ancestors[0][node] = parent;

            for (int level = 1; level < logN; level++)
                ancestors[level][node] =
                    ancestors[level - 1][ancestors[level - 1][node]];

            prefixMask[node] =
                (node == parent ? 0 : prefixMask[parent]) ^ charMask[node];

            stack.push_back({node, parent, 1});

            for (int child : adj[node])
                if (child != parent)
                    stack.push_back({child, node, 0});
        }
    }

    vector<int> parse(const string& query) {
        vector<int> numbers;

        for (int i = 0; i < query.size();) {
            if (isdigit(query[i])) {
                int number = 0;

                while (i < query.size() && isdigit(query[i]))
                    number = number * 10 + query[i++] - '0';

                numbers.push_back(number);
            } else {
                i++;
            }
        }

        return numbers;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        this->n = n;
        logN = 1;

        while ((1 << logN) <= n)
            logN++;

        adj.assign(n, {});

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        ancestors.assign(logN, vector<int>(n));
        entry.resize(n);
        exit.resize(n);
        charMask.resize(n);
        prefixMask.assign(n, 0);
        fenwick.assign(n + 1, 0);

        for (int i = 0; i < n; i++)
            charMask[i] = 1 << (s[i] - 'a');

        timer = 0;
        dfs();

        vector<bool> res;

        for (auto query : queries) {
            vector<int> numbers = parse(query);

            if (query.substr(0, 6) == "update") {
                update(numbers[0], query.back());
            } else {
                res.push_back(check(numbers[0], numbers[1]));
            }
        }

        return res;
    }
};
