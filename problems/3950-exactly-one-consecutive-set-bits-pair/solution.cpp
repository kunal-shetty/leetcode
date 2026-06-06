// 3950. Exactly One Consecutive Set Bits Pair
// Difficulty: Easy
// https://leetcode.com/problems/exactly-one-consecutive-set-bits-pair/
// Runtime: 0 ms (beats —)
// Memory: 7.9 MB (beats —)
// Submitted: 2026-06-06

class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        while(n > 0){
            if((n & 1) && ((n >> 1) & 1))
                count++;
            n >>= 1;
        }
        return count == 1;
    }
};
