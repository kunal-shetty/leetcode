// 3312. Sorted GCD Pair Queries
// Difficulty: Hard
// https://leetcode.com/problems/sorted-gcd-pair-queries/
// Runtime: 46 ms (beats —)
// Memory: 125.4 MB (beats —)
// Submitted: 2026-07-17

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        long long int mx = *max_element(nums.begin(), nums.end());

        vector<int> map(mx + 1, 0);
        for (auto it : nums) {
            map[it]++;
        }

        vector<long long> count(mx + 1, 0);

        for (int i = mx; i >= 1; i--) {
            long long curr = 0;

            for (int k = i; k <= mx; k += i) {
                curr += map[k];
            }

            count[i] = curr * (curr - 1) / 2;

            for (int k = 2 * i; k <= mx; k += i) {
                count[i] -= count[k];
            }
        }

        for (int i = 1; i <= mx; i++) {
            count[i] += count[i - 1];
        }

        vector<int> res;

        for (auto q : queries) {
            res.push_back(lower_bound(count.begin(), count.end(), q + 1) -
                          count.begin());
        }

        return res;
    }
};
