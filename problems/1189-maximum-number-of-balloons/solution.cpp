// 1189. Maximum Number of Balloons
// Difficulty: Easy
// https://leetcode.com/problems/maximum-number-of-balloons/
// Runtime: 0 ms (beats —)
// Memory: 8.9 MB (beats —)
// Submitted: 2026-06-22

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = count(text.begin(), text.end(), 'b');
        int a = count(text.begin(), text.end(), 'a');
        int n = count(text.begin(), text.end(), 'n');
        int l = count(text.begin(), text.end(), 'l') / 2;
        int o = count(text.begin(), text.end(), 'o') / 2;
        return min({b, a, n, l, o});
    }
};
