// 204. Count Primes
// Difficulty: Medium
// https://leetcode.com/problems/count-primes/
// Runtime: 177 ms (beats —)
// Memory: 12.5 MB (beats —)
// Submitted: 2026-07-02

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (sieve[i]) count++;
        }

        return count;
    }
};
