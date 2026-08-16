// 2029. Stone Game IX
// Difficulty: Medium
// https://leetcode.com/problems/stone-game-ix/
// Runtime: 7 ms (beats —)
// Memory: 131.3 MB (beats —)
// Submitted: 2026-08-16

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count[3] = {0, 0, 0};

        for (int i = 0; i < stones.size(); i++) {
            stones[i] %= 3;
            count[stones[i]]++;
        }

        if (count[0] % 2 == 0) {
            return count[1] != 0 && count[2] != 0;
        }

        return abs(count[2] - count[1]) >= 3;
    }
};
