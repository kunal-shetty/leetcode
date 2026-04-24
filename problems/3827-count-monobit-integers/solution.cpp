// 3827. Count Monobit Integers
// Difficulty: Easy
// https://leetcode.com/problems/count-monobit-integers/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-04-24

class Solution {
public:
    int countMonobit(int n) {
        int ans = 1;
        int v = 1;
        while (v <= n) {
            v = v << 1 | 1;
            ans++;
        }
        return ans;
    }
};
