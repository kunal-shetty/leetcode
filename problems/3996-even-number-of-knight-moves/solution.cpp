// 3996. Even Number of Knight Moves
// Difficulty: Easy
// https://leetcode.com/problems/even-number-of-knight-moves/
// Runtime: 4 ms (beats —)
// Memory: 49.7 MB (beats —)
// Submitted: 2026-07-19

class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return ((start[0] + start[1]) % 2) == ((target[0] + target[1]) % 2);
    }
};
