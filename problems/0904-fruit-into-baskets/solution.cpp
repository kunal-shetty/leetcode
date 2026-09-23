// 904. Fruit Into Baskets
// Difficulty: Medium
// https://leetcode.com/problems/fruit-into-baskets/
// Runtime: 27 ms (beats —)
// Memory: 85 MB (beats —)
// Submitted: 2026-09-23

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, maxLen = 0;
        unordered_map<int, int> basket;

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
