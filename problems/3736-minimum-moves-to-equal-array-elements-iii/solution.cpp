// 3736. Minimum Moves to Equal Array Elements III
// Difficulty: Easy
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
// Runtime: 0 ms (beats —)
// Memory: 31.6 MB (beats —)
// Submitted: 2026-06-25

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int MAX = INT_MIN, moves = 0;
        for(auto num : nums) MAX = max(MAX, num);
        for(auto num : nums) moves += MAX - num;
        return moves;
    }
};
