// 4032. Longest Subarray With at Most K Distinct Prime Factors
// Difficulty: Medium
// https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-prime-factors/
// Runtime: 623 ms (beats —)
// Memory: 255.8 MB (beats —)
// Submitted: 2026-08-23

class Solution {
public:
    vector<int> factors(int n) {
        vector<int> primes;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                primes.push_back(i);
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 1)
            primes.push_back(n);
        return primes;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> primes(n);
        for (int i = 0; i < n; i++) {
            primes[i] = factors(nums[i]);
        }
        unordered_map<int, int> c;
        int l = 0, uq = 0, res = 0;
        for (int r = 0; r < n; r++) {
            for (auto p : primes[r]) {
                if (++c[p] == 1)
                    uq++;
            }

            while (uq > k) {
                for (auto p : primes[l]) {
                    if (--c[p] == 0)
                        uq--;
                }
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
