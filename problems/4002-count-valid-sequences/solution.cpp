// 4002. Count Valid Sequences
// Difficulty: Medium
// https://leetcode.com/problems/count-valid-sequences/
// Runtime: 80 ms (beats —)
// Memory: 116.4 MB (beats —)
// Submitted: 2026-07-26

class Solution {
public:
    int MOD = 1e9 + 7;
    vector<long long> fact, inv;
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    long long nCr(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
    }
    int countValidSequences(int n, int k) {
        fact.resize(n + 1);
        inv.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv[n] = power(fact[n], MOD - 2);
        for (int i = n; i >= 1; i--)
            inv[i - 1] = inv[i] * i % MOD;
        long long ans = nCr(n - 1, k - 1);
        if ((n - k) % 2 == 0)
            ans = (ans - nCr((n + k - 2) / 2, k - 1) + MOD) % MOD;
        return ans;
    }
};
