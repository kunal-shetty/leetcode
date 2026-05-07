// 1513. Number of Substrings With Only 1s
// Difficulty: Medium
// https://leetcode.com/problems/number-of-substrings-with-only-1s/
// Runtime: 0 ms (beats —)
// Memory: 11.9 MB (beats —)
// Submitted: 2026-05-07

class Solution {
public:
    int numSub(string s) {
        int mod = 1e9 + 7;
        long count = 0;
        long sum = 0;

        for (char i : s) {
            if (i == '0') {
                sum += (count * (count + 1) / 2) % mod;
                count = 0;
            } else {
                count++;
            }
        }
        sum += (count * (count + 1) / 2) % mod;
        return sum%mod;
    }
};
