// 3348. Smallest Divisible Digit Product II
// Difficulty: Hard
// https://leetcode.com/problems/smallest-divisible-digit-product-ii/
// Runtime: 43 ms (beats —)
// Memory: 46.8 MB (beats —)
// Submitted: 2026-08-07

class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long x = t;

        for (int d = 2; d <= 9; d++)
            while (x % d == 0)
                x /= d;

        if (x > 1) return "-1";

        int n = num.size();
        vector<long long> rem(n + 1);
        rem[0] = t;

        int start = n - 1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                start = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], 1LL * (num[i] - '0'));
        }

        if (rem[n] == 1) return num;

        for (int i = start; i >= 0; i--) {
            char orig = num[i];

            for (char d = orig + 1; d <= '9'; d++) {
                num[i] = d;

                long long need = rem[i];
                need /= gcd(need, 1LL * (d - '0'));

                int cur = 9;
                for (int j = n - 1; j > i; j--) {
                    while (need % cur) cur--;
                    need /= cur;
                    num[j] = char(cur + '0');
                }

                if (need == 1)
                    return num;
            }

            num[i] = orig;
        }

        string ans;

        for (int d = 9; d >= 2; d--) {
            while (t % d == 0) {
                ans += char(d + '0');
                t /= d;
            }
        }

        ans += string(max(0, n + 1 - (int)ans.size()), '1');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
