// 3870. Count Commas in Range
// Difficulty: Easy
// https://leetcode.com/problems/count-commas-in-range/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-09-08

class Solution {
public:
    int countCommas(int n) {
       if(n < 1000) return 0;
       return n - 999;
    }
};
