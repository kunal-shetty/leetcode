// 3947. Maximum Number of Items From Sale II
// Difficulty: Medium
// https://leetcode.com/problems/maximum-number-of-items-from-sale-ii/
// Runtime: 323 ms (beats —)
// Memory: 318.2 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> factor(n + 1, 0);
        int cheap = INT_MAX;
        for(auto item: items){
            cheap = min(cheap, item[1]);
            factor[item[0]]++;
        }
    vector<int> divisible(n + 1,0);
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j += i){
                divisible[i] += factor[j];
            }
        }

        vector<pair<int, long long>> prem;
        for(auto item : items){
            int factor = item[0];
            int price = item[1];
            long long freeTarget = divisible[factor] - 1;
            if(freeTarget > 0 && price < 2 * cheap) prem.push_back({price, freeTarget});
        }
        sort(prem.begin(), prem.end());
        long long spent = 0, premium = 0, remaining = budget;
        for(auto [price,count] : prem){
            long long take = min(count, remaining / price);
            premium += take;
            spent += take * price;
            remaining -= take * price;
            if(remaining  == 0) break;
        }
        long long answer = 2LL * premium + (budget - spent) / cheap;
        return answer;
    }
};
