// 3954. Sum of Compatible Numbers in Range I
// Difficulty: Easy
// https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2026-06-07

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int i = max(1, n - k); i <= abs(n + k); i++){
            if(abs(n - i) <= k && (n & i) == 0) sum += i;
        }
        return sum;
    }
};
