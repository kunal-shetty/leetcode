// 1722. Minimize Hamming Distance After Swap Operations
// Difficulty: Medium
// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
// Runtime: 147 ms (beats —)
// Memory: 153.2 MB (beats —)
// Submitted: 2026-04-21

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;

        for(auto &p : allowedSwaps) {
            int a = p[0];
            int b = p[1];
            while(parent[a] != a) {
                parent[a] = parent[parent[a]];
                a = parent[a];
            }
            while(parent[b] != b) {
                parent[b] = parent[parent[b]];
                b = parent[b];
            }

            if(a != b) parent[a] = b;
        }

        unordered_map<int, vector<int>> groups;

        for(int i = 0; i < n; i++) {
            int x = i;
            while(parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            groups[x].push_back(i);
        }

        int ans = 0;

        for(auto &g : groups) {
            unordered_map<int, int> freq;

            for(int idx : g.second) {
                freq[source[idx]]++;
            }

            for(int idx : g.second) {
                if(freq[target[idx]] > 0) {
                    freq[target[idx]]--;
                } else {
                    ans++;
                }
            }
        }

        return ans;
    }
};
