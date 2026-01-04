// 1390. Four Divisors
// Difficulty: Medium
// https://leetcode.com/problems/four-divisors/
// Runtime: 5 ms (beats —)
// Memory: 16.1 MB (beats —)
// Submitted: 2026-01-04

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            int cnt = 0;
            int sum = 0;

            for (int d = 1; d * d <= n; d++) {
                if (n % d == 0) {
                    int d1 = d;
                    int d2 = n / d;

                    cnt++;
                    sum += d1;

                    if (d1 != d2) {
                        cnt++;
                        sum += d2;
                    }

                    if (cnt > 4) break; // early stop
                }
            }

            if (cnt == 4) ans += sum;
        }

        return ans;
    }
};
