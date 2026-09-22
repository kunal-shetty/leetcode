// 3274. Check if Two Chessboard Squares Have the Same Color
// Difficulty: Easy
// https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-09-22

class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        return (c1[0] + c2[0]) % 2 == (c1[1] + c2[1]) % 2;
    }
};
