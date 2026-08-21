// 3116. Kth Smallest Amount With Single Denomination Combination
// Difficulty: Hard
// https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
// Runtime: 131 ms (beats —)
// Memory: 20.7 MB (beats —)
// Submitted: 2026-08-21

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b, long long limit) {
        long long g = gcd(a, b);
        if (a / g > limit / b) return limit + 1; 
        return (a / g) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long cur = 1;
            bool ok = true;
            int bits = __builtin_popcount(mask);

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cur = lcm(cur, coins[i], x);
                    if (cur > x) {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok) continue;

            if (bits & 1) ans += x / cur;
            else ans -= x / cur;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
