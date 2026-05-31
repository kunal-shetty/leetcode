// 2894. Divisible and Non-divisible Sums Difference
// Difficulty: Easy
// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
// Runtime: 0 ms (beats —)
// Memory: 8.5 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for(int i = 1; i <= n; i++){
            if(i % m == 0) num2 += i;
            else num1 += i;
        }
        return num1 - num2;
    }
};
