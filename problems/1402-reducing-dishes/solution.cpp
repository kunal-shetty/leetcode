// 1402. Reducing Dishes
// Difficulty: Hard
// https://leetcode.com/problems/reducing-dishes/
// Runtime: 0 ms (beats —)
// Memory: 11.5 MB (beats —)
// Submitted: 2026-09-05

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        int sum = 0, res = 0, curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr += sum + satisfaction[i];
            sum += satisfaction[i];

            res = max(res, curr);
        }

        return res;
    }
};
