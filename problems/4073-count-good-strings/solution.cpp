// 4073. Count Good Strings
// Difficulty: Hard
// https://leetcode.com/problems/count-good-strings/
// Runtime: 0 ms (beats —)
// Memory: 8.4 MB (beats —)
// Submitted: 2026-10-04

class Solution {
public:
    const int MOD = 1e9 + 7;
    pair<long long, long long> fibonacci(long long n){
        if(n == 0) return {0, 1};
          auto [a, b] = fibonacci(n / 2);
        long long c = a  * ((2 * b % MOD - a + MOD) % MOD) % MOD;
        long long d = (a * a % MOD + b * b % MOD) % MOD;
        if(n & 1) return {d, (c + d) % MOD};
        return {c , d};
    }
    int countGoodStrings(long long n) {
        return 2 * fibonacci(n).first % MOD;
    }
};
