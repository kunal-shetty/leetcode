// 121. Best Time to Buy and Sell Stock
// Difficulty: Easy
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Runtime: 0 ms (beats —)
// Memory: 97.6 MB (beats —)
// Submitted: 2026-09-04

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int profit = 0;
        for(auto price : prices){
            profit = max(profit, price - minVal);
            minVal = min(price, minVal);        }
            return profit;
    }
    
};
