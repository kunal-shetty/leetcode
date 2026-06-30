// 1672. Richest Customer Wealth
// Difficulty: Easy
// https://leetcode.com/problems/richest-customer-wealth/
// Runtime: 0 ms (beats —)
// Memory: 11.9 MB (beats —)
// Submitted: 2026-06-30

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxVal = INT_MIN;
        for (auto account : accounts) 
            maxVal = max(maxVal, accumulate(account.begin(), account.end(), 0));
        return maxVal;
    }
};
