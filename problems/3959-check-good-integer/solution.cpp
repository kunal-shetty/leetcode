// 3959. Check Good Integer
// Difficulty: Easy
// https://leetcode.com/problems/check-good-integer/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-06-14

class Solution {
public:
    bool checkGoodInteger(int n) {
        int digit = 0;
        int sqr = 0;
        while(n){
            int rem = n % 10;

            digit += rem;
            sqr += rem * rem;
            n /= 10;
        }
        return sqr - digit >= 50;
    }
};
