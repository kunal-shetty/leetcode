// 3483. Unique 3-Digit Even Numbers
// Difficulty: Easy
// https://leetcode.com/problems/unique-3-digit-even-numbers/
// Runtime: 11 ms (beats —)
// Memory: 30.9 MB (beats —)
// Submitted: 2026-09-11

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> res;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    if (digits[k] % 2 != 0)
                        continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    res.insert(num);
                }
            }
        }
        return res.size();
    }
};
