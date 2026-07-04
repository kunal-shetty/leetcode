// 3981. Count Distinct Ways to Form Target from Two Strings
// Difficulty: Hard
// https://leetcode.com/problems/count-distinct-ways-to-form-target-from-two-strings/
// Runtime: 495 ms (beats —)
// Memory: 78.8 MB (beats —)
// Submitted: 2026-07-04

class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        int MOD = 1e9 + 7;
        int n1  = word1.size(), n2  = word2.size(), m = target.size();
        vector<vector<vector<long long>>> dp (m + 1, vector<vector<long long>>(n1 + 1, vector<long long>(n2 + 1, 0)));
        dp[0][0][0] = 1;

        for(int p = 0; p < m; p++){
            char c = target[p];
            for(int i = 0; i <= n1; i++){
                for(int j = 0; j <= n2; j++){
                    long long val = dp[p][i][j];
                    if(val == 0) continue;

                    for(int i2 = i; i2 < n1; i2++){
                        if(word1[i2] == c){
                            dp[p + 1][i2 + 1][j] = (dp[p +1][i2 + 1][j] + val) % MOD;
                        }
                    }
                    for(int j2 = j; j2 < n2; j2++){
                        if(word2[j2] == c){
                            dp[p + 1][i][j2 + 1] = (dp[p +1][i][j2 + 1] + val) % MOD;
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                ans = (ans + dp[m][i][j]) % MOD;
            }
        }
        return (int)ans;
    }
    
};
