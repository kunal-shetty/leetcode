// 657. Robot Return to Origin
// Difficulty: Easy
// https://leetcode.com/problems/robot-return-to-origin/
// Runtime: 4 ms (beats —)
// Memory: 10.5 MB (beats —)
// Submitted: 2026-07-15

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto move : moves){
            if(move == 'U') y++;
            if(move == 'D') y--;
            if(move == 'L') x--;
            if(move == 'R') x++;
        }
        return x == 0 && y == 0;
    }
};
