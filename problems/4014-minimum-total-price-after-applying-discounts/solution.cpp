// 4014. Minimum Total Price After Applying Discounts
// Difficulty: Medium
// https://leetcode.com/problems/minimum-total-price-after-applying-discounts/
// Runtime: 67 ms (beats —)
// Memory: 223.5 MB (beats —)
// Submitted: 2026-08-09

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());
        int n = prices.size();
        int m = discounts.size();
        int k = min(m, n);
        double total = 0.0;
        for(int i = 0; i < k; i ++){
            total += prices[i] *  (100.0 - discounts[i]) / 100.0;
            
        }
        for(int i =k ; i < n; i++){
         total+= prices[i];   
        }
        return total;
    }
    
    
};
