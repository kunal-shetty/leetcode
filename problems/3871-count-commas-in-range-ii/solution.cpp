// 3871. Count Commas in Range II
// Difficulty: Medium
// https://leetcode.com/problems/count-commas-in-range-ii/
// Runtime: 0 ms (beats —)
// Memory: 9.1 MB (beats —)
// Submitted: 2026-09-09

class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) return 0;
        long long ans = 0;
        long long start = 1000;
        int commas = 1;

        while (start <= n) {
            long long end = start * 1000 - 1;
            ans += (min(n, end) - start + 1) * commas;
            start *= 1000;
            commas++;
        }

        return ans;
    }
};
