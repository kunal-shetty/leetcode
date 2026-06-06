// 3753. Total Waviness of Numbers in Range II
// Difficulty: Hard
// https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/
// Runtime: 21 ms (beats —)
// Memory: 21.1 MB (beats —)
// Submitted: 2026-06-06

using ll = long long;

class Solution {
public:
    vector<int> wavy;
    bool calcWavy() {
        for (int i = 0; i < 1000; i++) {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            if ((b > a && b > c) || (b < a && b < c)) {
                wavy.push_back(i);
            }
        }
        return true;
    }

    ll totalWaviness(ll num1, ll num2) {
        calcWavy();
        return countUntil(num2) - countUntil(num1 - 1);
    }

    ll countUntil(ll num) {
        if (num < 100)
            return 0;

        ll res = 0;

        for (int pattern : wavy) {
            res += countPatternOccurrences(num, pattern);
        }

        return res;
    }

    ll countPatternOccurrences(ll num, int pattern) {
        ll count = 0;
        ll mult = 1;

        bool leadingZeroPattern = (pattern < 100);

        while (mult <= num) {
            ll prefix = num / (mult * 1000);
            ll curr = (num / mult) % 1000;
            ll suffix = num % mult;

            ll ways = 0;
            ll edge = 0;

            if (curr > pattern) {
                ways = prefix - leadingZeroPattern + 1;
            } else if (curr == pattern) {
                ways = max(0LL, prefix - leadingZeroPattern);
                edge = (prefix >= leadingZeroPattern) * (suffix + 1);
            } else {
                ways = max(0LL, prefix - leadingZeroPattern);
            }

            count += ways * mult + edge;
            mult *= 10;
        }

        return count;
    }
};
