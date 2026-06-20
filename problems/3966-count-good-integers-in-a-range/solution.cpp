// 3966. Count Good Integers in a Range
// Difficulty: Hard
// https://leetcode.com/problems/count-good-integers-in-a-range/
// Runtime: 4 ms (beats —)
// Memory: 10.5 MB (beats —)
// Submitted: 2026-06-20

class Solution {
public:
    long long dp[20][11][2][2];
    string s;
    int K;
    long long dfs(int pos, int prev, int tight, int started) {
        if (pos == s.size()) {
            return started;
        }

        long long &res = dp[pos][prev][tight][started];
        if (res != -1 && !tight)
            return res;

        long long ans = 0;
        int limit = tight ? s[pos] - '0' : 9;

        for (int i = 0; i <= limit; i++) {
            int newTight = tight && (i == limit);

            if (!started) {
                if (i == 0)
                    ans += dfs(pos + 1, 10, newTight, 0);
                else
                    ans += dfs(pos + 1, i, newTight, 1);
            } else {
                if (abs(i - prev) <= K)
                    ans += dfs(pos + 1, i, newTight, 1);
            }
        }
        if (!tight)
            res = ans;
        return ans;
    }

    long long count(long long x) {
        if (x <= 0)
            return 0;
        s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return dfs(0, 10, 1, 0);
    }
    long long goodIntegers(long long l, long long r, int k) {

        K = k;
        return count(r) - count(l - 1);
    }
};
