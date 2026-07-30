// 3014. Minimum Number of Pushes to Type Word I
// Difficulty: Easy
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
// Runtime: 0 ms (beats —)
// Memory: 8.4 MB (beats —)
// Submitted: 2026-07-30

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int blocks = n / 8;
        return (blocks * (blocks + 1) * 4) + (n % 8) * (blocks + 1);
    }
};
