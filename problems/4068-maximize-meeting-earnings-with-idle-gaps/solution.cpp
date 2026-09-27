// 4068. Maximize Meeting Earnings with Idle Gaps
// Difficulty: Hard
// https://leetcode.com/problems/maximize-meeting-earnings-with-idle-gaps/
// Runtime: 64 ms (beats —)
// Memory: 195 MB (beats —)
// Submitted: 2026-09-27

class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b){
            return a[1] <b[1]; 
        });
        int n = meetings.size();
        vector<long long> dp(n), best(n), ends(n);
        for(int i = 0; i < n; i++) ends[i] = meetings[i][1];
        long long res= 0;
        for(int i=0; i < n;i++){
            int idx =upper_bound(ends.begin(), ends.end(), meetings[i][0]) - ends.begin() - 1;

            dp[i] = meetings[i][2];
            if(idx >= 0){
                dp[i] = max(dp[i], 1LL * meetings[i][2] + meetings[i][0] + best[idx]);
            }

            best[i] = dp[i] - meetings[i][1];
            if(i) best[i] = max(best[i], best[i - 1]);
            res = max(res, dp[i]);
        }
        return res;
    }
};
