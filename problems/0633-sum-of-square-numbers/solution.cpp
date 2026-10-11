// 633. Sum of Square Numbers
// Difficulty: Medium
// https://leetcode.com/problems/sum-of-square-numbers/
// Runtime: 2 ms (beats —)
// Memory: 7.7 MB (beats —)
// Submitted: 2026-10-11

class Solution {
public:
    bool judgeSquareSum(int c) {
    long long a = 0;
    long long b = sqrt(c);
    
    while (a <= b) {
        long long sum = a * a + b * b;
        
        if (sum == c)  return true; 
        else if (sum < c)  a++;
        else  b--;    
    }
    
    return false; 
}

};
