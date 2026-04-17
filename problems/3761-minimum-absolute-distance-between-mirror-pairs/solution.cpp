// 3761. Minimum Absolute Distance Between Mirror Pairs
// Difficulty: Medium
// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
// Runtime: 123 ms (beats —)
// Memory: 131.9 MB (beats —)
// Submitted: 2026-04-17

class Solution {
public:
    int reverseNum(int n) {
        int rev = 0;
        while (n) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }
            mp[reverseNum(nums[i])] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
