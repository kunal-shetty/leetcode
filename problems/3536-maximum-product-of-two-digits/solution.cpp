// 3536. Maximum Product of Two Digits
// Difficulty: Easy
// https://leetcode.com/problems/maximum-product-of-two-digits/
// Runtime: 0 ms (beats —)
// Memory: 8.5 MB (beats —)
// Submitted: 2026-07-25

class Solution {
public:
    int maxProduct(int n) {
        int firstMax = 0, secondMax = 0;
        while(n){
            int remainder = n % 10;
            if(remainder > firstMax){
                secondMax = firstMax;
                firstMax = remainder;
            }
            else if(remainder > secondMax){
                secondMax = remainder;
            }
            n /= 10;
        }
        return firstMax * secondMax;
    }
};
