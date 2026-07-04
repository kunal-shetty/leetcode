// 2492. Minimum Score of a Path Between Two Cities
// Difficulty: Medium
// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
// Runtime: 103 ms (beats —)
// Memory: 144.2 MB (beats —)
// Submitted: 2026-07-04

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto r : roads){
            adj[r[0]].push_back({r[1], r[2]});
                      adj[r[1]].push_back({r[0], r[2]});
        }

        int res = INT_MAX;
        vector<bool> visited(n + 1, false);

        queue<int> q;
        q.push(1);
        visited[1] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                res = min(res, it.second);

                if(!visited[it.first]){
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }

        return res;
    }
};
