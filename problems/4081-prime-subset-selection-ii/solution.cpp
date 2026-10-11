// 4081. Prime Subset Selection II
// Difficulty: Hard
// https://leetcode.com/problems/prime-subset-selection-ii/
// Runtime: 39 ms (beats —)
// Memory: 58.6 MB (beats —)
// Submitted: 2026-10-11

class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
            }
        }
        vector<int> res;
        vector<int> p;
        for (int i = 2; i <= n; i++) {
            if (prime[i])
                p.push_back(i);
        }
        const int INF = 1e9;
        int m = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(s + 1, INF));
        dp[m][0] = 0;

        for (int i = m -1; i >=0;i--){
        dp[i] = dp[i + 1];
            for(int  j =p[i]; j <= s;j++){
                if(dp[i + 1][j - p[i]] != INF ){
                    dp[i][j] = min(dp[i][j], dp[i + 1][ j - p[i]] + 1);
                }
            }
        }

        
        int sum = s;
        while (sum > 0 && dp[0][sum] == INF)
            sum--;
        if (sum == 0)
            return {};
        int need = dp[0][sum];
        for (int i =0; i < m && need >0; i++) {
            if (sum >= p[i] && dp[i + 1][sum - p[i]] == need - 1) {
                res.push_back(p[i]);
                sum -= p[i];
                need--;
            }
        }
 
        return res;
    }
};
