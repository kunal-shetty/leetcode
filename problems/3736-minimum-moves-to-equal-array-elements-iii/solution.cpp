// 3736. Minimum Moves to Equal Array Elements III
// Difficulty: Easy
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
// Runtime: 2 ms (beats 13.3%)
// Memory: 31.3 MB (beats 98.4%)
// Submitted: 2026-11-03

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int MAX = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for(auto num : nums){
            moves += MAX - num;
        }
        return moves;
    }
};
