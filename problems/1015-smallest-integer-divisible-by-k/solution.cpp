// 1015. Smallest Integer Divisible by K
// Difficulty: Medium
// https://leetcode.com/problems/smallest-integer-divisible-by-k/
// Runtime: 0 ms (beats —)
// Memory: 7.9 MB (beats —)
// Submitted: 2026-01-04

class Solution {
public:
    int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0)
        return -1;

    int remainder = 0;

    for (int len = 1; len <= k; len++) {
        remainder = (remainder * 10 + 1) % k;
        if (remainder == 0)
            return len;
    }

    return -1;
}

};
