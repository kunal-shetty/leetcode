// 1611. Minimum One Bit Operations to Make Integers Zero
// Difficulty: Hard
// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
// Runtime: 0 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-08-15

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
