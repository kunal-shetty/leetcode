// 2958. Length of Longest Subarray With at Most K Frequency
// Difficulty: Medium
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Runtime: 69 ms (beats —)
// Memory: 149.5 MB (beats —)
// Submitted: 2026-08-12

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, start = -1;
        unordered_map<int, int> freq;
        
        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;
            while (freq[nums[end]] > k) {
                start++;
                freq[nums[start]]--;
            }
            ans = max(ans, end - start);
        }
        
        return ans;
    }
};
