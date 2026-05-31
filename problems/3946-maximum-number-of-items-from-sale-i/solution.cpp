// 3946. Maximum Number of Items From Sale I
// Difficulty: Medium
// https://leetcode.com/problems/maximum-number-of-items-from-sale-i/
// Runtime: 135 ms (beats —)
// Memory: 145.3 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> factor(1501, 0);
        for (auto item : items) {
            factor[item[0]]++;
        }

        vector<int> divisible(1501, 0);
        for (int i = 1; i <= 1500; i++) {
            for (int j = i; j <= 1500; j += i) {
                divisible[i] += factor[j];
            }
        }

        vector<int> bonus(n);
        for (int j = 0; j < n; j++) {
            bonus[j] = divisible[items[j][0]] - 1;
        }
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int free = bonus[i];
            auto newDP = dp;
for (int i = budget; i >= price; i--) {
                newDP[i] = max(newDP[i], dp[i - price] + free + 1);
            }
            for (int i = price; i <= budget; i++) {
                newDP[i] = max(newDP[i], newDP[i - price] + 1);
            }
            
            dp = newDP;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
