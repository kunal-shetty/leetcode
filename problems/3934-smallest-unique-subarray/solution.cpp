// 3934. Smallest Unique Subarray
// Difficulty: Hard
// https://leetcode.com/problems/smallest-unique-subarray/
// Runtime: 696 ms (beats —)
// Memory: 387.7 MB (beats —)
// Submitted: 2026-05-17

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const unsigned long long base = 100003;

        vector<unsigned long long> pref(n + 1, 0);
        vector<unsigned long long> power(n + 1, 1);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] * base + nums[i] + 1;
            power[i + 1] = power[i] * base;
        }
        auto getHash = [&](int l, int r) {
            return pref[r + 1] - pref[l] * power[r - l + 1];
        };

        auto check = [&](int len) {
            unordered_map<unsigned long long, int> freq;

            for (int i = 0; i + len <= n; i++) {
                freq[getHash(i, i + len - 1)]++;
            }

            for (auto& p : freq) {
                if (p.second == 1) {
                    return true;
                }
            }

            return false;
        };
        int l = 1, r = n;
        int ans = n;

        while (l <= r) {

            int mid = (l + r) / 2;

            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
