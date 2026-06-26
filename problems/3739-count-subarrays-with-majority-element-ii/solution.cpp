// 3739. Count Subarrays With Majority Element II
// Difficulty: Hard
// https://leetcode.com/problems/count-subarrays-with-majority-element-ii/
// Runtime: 0 ms (beats —)
// Memory: 95.6 MB (beats —)
// Submitted: 2026-06-26

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int size = nums.size(), pref = size;

        vector<int> freq(2 * size + 1);
        freq[size] = 1;

        long long l = 0, ans = 0;

        for (int num : nums) {
            if (num == target)
                l += freq[pref++];
            else
                l -= freq[--pref];

            ++freq[pref];
            ans += l;
        }

        return ans;
    }
};
