// 3655. XOR After Range Multiplication Queries II
// Difficulty: Hard
// https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/
// Runtime: 472 ms (beats —)
// Memory: 431.2 MB (beats —)
// Submitted: 2026-04-09

class Solution {
public:
    int xorAfterQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int blockSize = sqrt(n) + 1;

        vector<vector<vector<int>>> buckets(blockSize);

        for (auto &q : queries) {
            int left = q[0], right = q[1], step = q[2], value = q[3];

            if (step < blockSize) {
                buckets[step].push_back(q);
            } else {
                for (int i = left; i <= right; i += step)
                    arr[i] = (1LL * arr[i] * value) % MOD;
            }
        }

        for (int step = 1; step < blockSize; step++) {
            if (buckets[step].empty()) continue;

            vector<long long> multiplier(n + step + 5, 1);

            for (auto &q : buckets[step]) {
                int left = q[0], right = q[1], value = q[3];

                int lastIndex = left + (right - left) / step * step;
                int stopIndex = lastIndex + step;

                multiplier[left] = (multiplier[left] * value) % MOD;

                long long base = value, exp = MOD - 2, inv = 1;
                while (exp) {
                    if (exp & 1) inv = inv * base % MOD;
                    base = base * base % MOD;
                    exp >>= 1;
                }

                multiplier[stopIndex] = (multiplier[stopIndex] * inv) % MOD;
            }

            for (int i = 0; i < n; i++) {
                if (i >= step)
                    multiplier[i] = (multiplier[i] * multiplier[i - step]) % MOD;
            }

            for (int i = 0; i < n; i++) {
                arr[i] = (1LL * arr[i] * multiplier[i]) % MOD;
            }
        }

        int result = 0;
        for (int value : arr)
            result ^= value;

        return result;
    }
};
