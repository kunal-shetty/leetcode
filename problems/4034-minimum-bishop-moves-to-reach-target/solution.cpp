// 4034. Minimum Bishop Moves to Reach Target
// Difficulty: Medium
// https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/
// Runtime: 0 ms (beats —)
// Memory: 50.4 MB (beats —)
// Submitted: 2026-08-29

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];
        if(sr == tr && sc == tc) return 0;
        if((sr + sc) % 2 != (tc + tr) % 2) return -1;
        if(abs(sr - tr) == abs(tc - sc)) return 1;
        return 2;
    }
};
