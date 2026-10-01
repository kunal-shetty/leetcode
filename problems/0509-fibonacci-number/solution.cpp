// 509. Fibonacci Number
// Difficulty: Easy
// https://leetcode.com/problems/fibonacci-number/
// Runtime: 0 ms (beats —)
// Memory: 7.7 MB (beats —)
// Submitted: 2026-10-01

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0, b = 1, c;
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
