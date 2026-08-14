// 3666. Minimum Operations to Equalize Binary String
// Difficulty: Hard
// https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/
// Runtime: 3 ms (beats —)
// Memory: 19.2 MB (beats —)
// Submitted: 2026-08-14

class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.size(), one = 0, zero = 0;
        for (char ch : s)
            if (ch == '0')
                zero++;
        one = n - zero;
        if (zero == 0)
            return 0;
        for (int round = 1; round <= n; round++) {
            int flips = round * k;
            if ((flips - zero) % 2 || flips < zero)
                continue;
            if (round % 2) {
                if (flips <= zero * round + one * (round - 1))
                    return round;
            } else {
                if (flips <= zero * (round - 1) + one * round)
                    return round;
            }
        }
        return -1;
    }
};
