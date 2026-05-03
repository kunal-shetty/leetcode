// 743. Network Delay Time
// Difficulty: Medium
// https://leetcode.com/problems/network-delay-time/
// Runtime: 104 ms (beats —)
// Memory: 40.6 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        for(int i = 0; i < n - 1; i++)
            for(auto &e : times)
                if(dist[e[0]] != 1e9)
                    dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
