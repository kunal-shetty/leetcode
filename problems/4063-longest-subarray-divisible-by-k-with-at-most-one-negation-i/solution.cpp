// 4063. Longest Subarray Divisible by K with At Most One Negation I
// Difficulty: Medium
// https://leetcode.com/problems/longest-subarray-divisible-by-k-with-at-most-one-negation-i/
// Runtime: 1057 ms (beats —)
// Memory: 346.5 MB (beats —)
// Submitted: 2026-09-26

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                sum += nums[j];
                st.insert(((2LL * nums[j]) % k + k) % k);
                int r = ((sum % k) + k) % k;
                if (r == 0 || st.count(r))
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
