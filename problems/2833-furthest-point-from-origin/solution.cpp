// 2833. Furthest Point From Origin
// Difficulty: Easy
// https://leetcode.com/problems/furthest-point-from-origin/
// Runtime: 3 ms (beats —)
// Memory: 9.1 MB (beats —)
// Submitted: 2026-04-24

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count = 0;
        int x = 0;
        for(char m : moves){
            if(m == 'L') x++;
            if(m == 'R') x--;
            if(m == '_') count++;
        }
        return count + abs(x);
     }
};
