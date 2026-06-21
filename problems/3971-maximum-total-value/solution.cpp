// 3971. Maximum Total Value
// Difficulty: Hard
// https://leetcode.com/problems/maximum-total-value/
// Runtime: 159 ms (beats —)
// Memory: 423.3 MB (beats —)
// Submitted: 2026-06-21

class Solution {
public:
    long long count(long long t, vector<int> v, vector<int> d) {
        long long res = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= t)
                res += (v[i] - t) / d[i] + 1;
        }
        return res;
    }
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long MOD = 1e9 + 7;
        int n = value.size();
        long long l = 0, r = 1e9;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            if (count(mid, value, decay) >= m)
                l = mid;
            else
                r = mid - 1;
        }

        long long t = l, count = 0, ans = 0;

        for (int i = 0; i < value.size(); i++) {
            long long a = value[i], d = decay[i];

            if (a <= t)
                continue;

            long long k = (a - t - 1) / d + 1;
            count += k;
            long long sum = k * a - d * k * (k - 1) / 2;
            ans = (ans + sum % MOD) % MOD;
        }
        ans = (ans + ((m - count) % MOD) * (t % MOD)) % MOD;
        return ans;
    }
};
