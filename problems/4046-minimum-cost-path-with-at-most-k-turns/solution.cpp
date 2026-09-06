// 4046. Minimum Cost Path With At Most K Turns
// Difficulty: Hard
// https://leetcode.com/problems/minimum-cost-path-with-at-most-k-turns/
// Runtime: 982 ms (beats —)
// Memory: 74.4 MB (beats —)
// Submitted: 2026-09-06

class Solution {
    using T = tuple<long long,int,int,int,int>;
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1)
            return grid[0][0];
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1,1};
        const long long INF  = 1e18;
        int S = m * n * 4 * (k + 1);

        vector<long long> dist(S, INF);

        auto id = [&](int r, int c, int d, int t){
            return (((r * n + c) * 4 + d) * (k + 1) + t);
        };

            priority_queue<T, vector<T>, greater<T>> pq;
        for(int d=0; d <4;d++){
            int nr = dr[d], nc = dc[d];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    long long cost = grid[0][0] + grid[nr][nc];
                dist[id(nr, nc, d, 0)] = cost;
                pq.push({cost, nr, nc, d, 0});
            }
            
        }
        while(!pq.empty()){
            auto [cost, r, c, d, t] = pq.top(); pq.pop();
            if(cost != dist[id(r,c,d,t)]) continue;
            for(int nd = 0; nd < 4; nd++){
                int nr = r + dr[nd], nc = c + dc[nd];
                if(nr <0 || nr >= m || nc < 0 || nc >= n) continue;
                int nt = t + (nd != d);
                if(nt > k) continue;

                long long ncost = cost + grid[nr][nc];
                int idx = id(nr, nc,nd ,nt);
                    if(ncost < dist[idx]){
                        dist[idx] = ncost;
                        pq.push({ncost, nr, nc,nd,nt});
                    }
            }
        }
        long long res = INF;
        for(int i = 0; i <4; i ++){
            for(int j = 0; j <=k; j++){
                res = min(res, dist[id(m - 1,n - 1, i, j)]);
            }
        }
        return res ==INF ? -1 : res;
    }
};
