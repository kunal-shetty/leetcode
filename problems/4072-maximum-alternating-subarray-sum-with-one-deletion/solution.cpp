// 4072. Maximum Alternating Subarray Sum With One Deletion
// Difficulty: Medium
// https://leetcode.com/problems/maximum-alternating-subarray-sum-with-one-deletion/
// Runtime: 35 ms (beats —)
// Memory: 207.3 MB (beats —)
// Submitted: 2026-10-04

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long INF = -1e18;
        long long dp[2][2] = { {INF, INF}, { INF, INF}};
        long long res = INF;
        for(auto num : nums){
            long long newDP[2][2] = { {INF, INF}, { INF, INF}};
            newDP[1][0] = num;
            for(int i = 0; i < 2;i++){
                for(int j = 0; j < 2;j++){
                    if(dp[i][j] ==INF) continue;

                    long long val = dp[i][j] + (i ? -num : num);
                    newDP[i ^ 1][j] = max(newDP[i ^ 1][j], val);

                    if(!j){
                        newDP[i][1] = max(newDP[i][1], dp[i][j]);
                    }
                }
            }
           memcpy(dp, newDP, sizeof(dp));
       for(int i = 0; i < 2;i++){
                for(int j = 0; j < 2;j++){
                    res = max(res, dp[i][j]);
                }}
        }
        return res;
    }
};
