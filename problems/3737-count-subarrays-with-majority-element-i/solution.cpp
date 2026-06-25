// 3737. Count Subarrays With Majority Element I
// Difficulty: Medium
// https://leetcode.com/problems/count-subarrays-with-majority-element-i/
// Runtime: 27 ms (beats —)
// Memory: 41.1 MB (beats —)
// Submitted: 2026-06-25

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (pref[r + 1] - pref[l] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
