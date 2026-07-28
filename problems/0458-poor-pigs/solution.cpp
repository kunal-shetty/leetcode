// 458. Poor Pigs
// Difficulty: Hard
// https://leetcode.com/problems/poor-pigs/
// Runtime: 0 ms (beats —)
// Memory: 7.7 MB (beats —)
// Submitted: 2026-07-28

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest / minutesToDie + 1;
        long n = 1;
        int ans = 0;

        while (n < buckets) {
            n *= base;
            ans++;
        }
        return ans;
    }
};
