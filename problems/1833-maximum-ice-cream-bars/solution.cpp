// 1833. Maximum Ice Cream Bars
// Difficulty: Medium
// https://leetcode.com/problems/maximum-ice-cream-bars/
// Runtime: 35 ms (beats —)
// Memory: 80.1 MB (beats —)
// Submitted: 2026-06-21

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for(auto cost : costs){
            if(coins < cost) return count;
            count++; coins -= cost;
        }
        return count;
    }
};
