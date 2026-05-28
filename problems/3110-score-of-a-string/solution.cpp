// 3110. Score of a String
// Difficulty: Easy
// https://leetcode.com/problems/score-of-a-string/
// Runtime: 0 ms (beats —)
// Memory: 8.9 MB (beats —)
// Submitted: 2026-05-28

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 1; i < s.length(); i++){
            score += abs(s[i] - s[i - 1]);
        }
        return score;
    }
};
