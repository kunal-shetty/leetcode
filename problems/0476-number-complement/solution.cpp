// 476. Number Complement
// Difficulty: Easy
// https://leetcode.com/problems/number-complement/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-03-11

class Solution {
public:
    int countBits(int n) {
        int bits = 0;

        while (n > 0) {
            bits++;
            n >>= 1;
        }

        return bits;
    }
    int findComplement(int num) {
        if (num == 0)
            return 1;
        int bits = countBits(num);
        return pow(2, bits) - num - 1;
    }
};
