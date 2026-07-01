// 122. Best Time to Buy and Sell Stock II
// Difficulty: Medium
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Runtime: 0 ms (beats —)
// Memory: 19.9 MB (beats —)
// Submitted: 2026-07-01

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
