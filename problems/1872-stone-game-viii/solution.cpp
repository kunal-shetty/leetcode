// 1872. Stone Game VIII
// Difficulty: Hard
// https://leetcode.com/problems/stone-game-viii/
// Runtime: 104 ms (beats —)
// Memory: 87.1 MB (beats —)
// Submitted: 2026-08-24

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; i++) 
            stones[i] += stones[i - 1];
        int best = stones[n - 1];
        for (int i = n - 2; i >= 1; i--) 
            best = max(best, stones[i] - best);
       
        return best;
    }
};
