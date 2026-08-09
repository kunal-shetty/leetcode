// 4016. Maximum Area of Two Non-Overlapping Square Submatrices
// Difficulty: Medium
// https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/
// Runtime: 65 ms (beats —)
// Memory: 126.3 MB (beats —)
// Submitted: 2026-08-09

class Solution {
public:

    vector<vector<int>> dp;
    int m,n;
    bool check(int k){
        int R = m - k + 1, C = n - k + 1;
        if(R <= 0 || C <= 0) return false;
        vector<int> row(R), col(C);
        for(int r = 0; r < R; r++)
            for(int c = 0; c < C; c++)
                if(dp[r + k - 1][c + k - 1] >= k) row[r] = col[c] = 1;

        vector<int> preR(R + 1), preC(C + 1);
        for(int i = 0 ; i < R; i++) preR[i + 1] = preR[i] + row[i];
        for(int i = 0 ; i < C; i++) preC[i + 1] = preC[i] + col[i];


            for(int r = 0; r + k < R; r++)
            if(row[r] && preR[R] - preR[r + k]) return true;

        for(int c = 0; c + k < C; c++)
            if(col[c] && preC[C] - preC[c + k]) return true;
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        dp.assign(m, vector<int>(n));
        for(int  i = 0; i < m; i++)
            for(int j = 0; j < n; j ++)
                if(mat[i][j]) dp[i][j] = (i && j) ? 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) : 1;
               int l = 1, r = min(m , n), ans = 0;

        while(l <= r){
            int mid = (l + r) / 2;

            if(check(mid)) ans = mid, l = mid + 1;
            else  r = mid - 1;
        }
        return ans * ans;
            
        
    }
};
