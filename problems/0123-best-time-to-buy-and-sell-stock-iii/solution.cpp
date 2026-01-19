// 123. Best Time to Buy and Sell Stock III
// Difficulty: Hard
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Runtime: 0 ms (beats —)
// Memory: 79.2 MB (beats —)
// Submitted: 2026-01-19

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, buy2 = INT_MIN;
        int sell1 = 0, sell2 = 0;

        for (int price : prices) {
            buy1  = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);

            buy2  = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};
