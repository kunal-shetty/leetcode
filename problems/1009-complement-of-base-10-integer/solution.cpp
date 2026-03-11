// 1009. Complement of Base 10 Integer
// Difficulty: Easy
// https://leetcode.com/problems/complement-of-base-10-integer/
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
    int bitwiseComplement(int n) {
       if(n == 0) return 1;
       int bits = countBits(n);
       return pow(2, bits) - n - 1; 
    }
};
