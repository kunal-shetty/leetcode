// 2144. Minimum Cost of Buying Candies With Discount
// Difficulty: Easy
// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
// Runtime: 6 ms (beats —)
// Memory: 16.9 MB (beats —)
// Submitted: 2026-06-01

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int minCost = 0;
        for(int i = 0; i < cost.size(); i++){
            if(i % 3 == 2) continue;
            minCost += cost[i];
        }
        return minCost;
    }
};
