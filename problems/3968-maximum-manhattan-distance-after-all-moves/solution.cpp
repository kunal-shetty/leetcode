// 3968. Maximum Manhattan Distance After All Moves
// Difficulty: Medium
// https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/
// Runtime: 12 ms (beats —)
// Memory: 22.2 MB (beats —)
// Submitted: 2026-06-21

class Solution {
public:
    int maxDistance(string moves) {
        int x =0, y = 0, blank = 0;
        for(char c : moves){
            if(c == 'R') x++;
            else if(c == 'L') x--;
            else if(c == 'U') y++;
            else if(c =='D') y--;
            else blank++;
        }
        return abs(x) + abs(y) + blank;
    }
};
