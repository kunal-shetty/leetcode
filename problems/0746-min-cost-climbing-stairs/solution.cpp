// 746. Min Cost Climbing Stairs
// Difficulty: Easy
// https://leetcode.com/problems/min-cost-climbing-stairs/
// Runtime: 0 ms (beats —)
// Memory: 17.5 MB (beats —)
// Submitted: 2026-08-08

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 2; i <= cost.size(); i++) {
            int curr = min(prev1 + cost[i - 1],
                           prev2 + cost[i - 2]);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
