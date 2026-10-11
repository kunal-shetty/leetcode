// 4078. Three Fibonacci Sum
// Difficulty: Easy
// https://leetcode.com/problems/three-fibonacci-sum/
// Runtime: 0 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-10-11

class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0, b = 1;
        while(a + b + (a + b) <= n){
            int c=a+b;
            if(a + b + c == n) return true;
            a = b;
            b = c;
        }
        return false;
    }
};
