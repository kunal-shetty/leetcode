// 3881. Direction Assignments with Exactly K Visible People
// Difficulty: Medium
// https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/
// Runtime: 47 ms (beats —)
// Memory: 74.8 MB (beats —)
// Submitted: 2026-03-28

class Solution {
public:
    static const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int countVisiblePeople(int n, int pos, int k) {
        vector<long long> fact(n), invFact(n);

        fact[0] = 1;
        for (int i = 1; i < n; i++) fact[i] = fact[i-1] * i % MOD;

        invFact[n-1] = power(fact[n-1], MOD - 2);
        for (int i = n - 2; i >= 0; i--) invFact[i] = invFact[i+1] * (i+1) % MOD;

        if (k > n - 1) return 0;

        long long comb = fact[n-1] * invFact[k] % MOD * invFact[n-1-k] % MOD;

        return (2 * comb) % MOD;
    }
};
