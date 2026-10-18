// 4456. last visited cell in a directional grid
// Difficulty: Unknown
// https://leetcode.com/problems/last-visited-cell-in-a-directional-grid/
// Runtime: 50 ms (beats 44.4%)
// Memory: 144.3 MB (beats 66.7%)
// Submitted: 2026-10-18

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));
        int i =0,j=0;
        while(1){
            vis[i][j] = true;
            int r=i,c =j;
            if(grid[i][j] =='L') c--;
            else if(grid[i][j] =='R') c++;
            else if(grid[i][j] =='U') r--;
            else r++;

            if(r <0 || r>=m || c <0 || c>= n|| vis[r][c])  return {i,j};
            i = r; j =c;
        }
        return {};
    }
};
