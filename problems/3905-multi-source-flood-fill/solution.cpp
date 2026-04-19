// 3905. Multi Source Flood Fill
// Difficulty: Medium
// https://leetcode.com/problems/multi-source-flood-fill/
// Runtime: 134 ms (beats —)
// Memory: 209.5 MB (beats —)
// Submitted: 2026-04-19

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, -1));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < sources.size(); i++){
            int r = sources[i][0];
            int c = sources[i][1];
            int col = sources[i][2];
            grid[r][c] = col;
            dist[r][c] = 0;
            q.push(make_pair(r,c));
        }
        
        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};
        
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            
            int r = cur.first;
            int c = cur.second;
            
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(dist[nr][nc] == -1){
                        dist[nr][nc] = dist[r][c] + 1;
                        grid[nr][nc] = grid[r][c];
                        q.push(make_pair(nr,nc));
                    }
                    else if(dist[nr][nc] == dist[r][c] + 1){
                        if(grid[r][c] > grid[nr][nc]){
                            grid[nr][nc] = grid[r][c];
                        }
                    }
                }
            }
        }
        
        return grid;
    }
};
