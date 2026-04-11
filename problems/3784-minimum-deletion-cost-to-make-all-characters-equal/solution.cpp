// 3784. Minimum Deletion Cost to Make All Characters Equal
// Difficulty: Medium
// https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/
// Runtime: 0 ms (beats —)
// Memory: 115 MB (beats —)
// Submitted: 2026-04-11

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long totalCost = 0;
        vector<long long> charCost(26, 0);

        for (int i = 0; i < s.size(); i++) {
            charCost[s[i] - 'a'] += cost[i];
            totalCost += cost[i];
        }

        long long maxima = 0;
        for (int i = 0; i < 26; i++) {
            maxima = max(maxima, charCost[i]);
        }

        return totalCost - maxima;
    }
};
