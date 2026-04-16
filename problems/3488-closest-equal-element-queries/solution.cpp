// 3488. Closest Equal Element Queries
// Difficulty: Medium
// https://leetcode.com/problems/closest-equal-element-queries/
// Runtime: 219 ms (beats —)
// Memory: 214 MB (beats —)
// Submitted: 2026-04-16

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        int m = nums.size();
        vector<int> prev(m, -1), next(m, -1);
        unordered_map<int, int> mp;

        for (int i = 0; i < m; i++) {
            if (mp.count(nums[i])) prev[i] = mp[nums[i]];
            mp[nums[i]] = i;
        }

        mp.clear();
        for (int i = m - 1; i >= 0; i--) {
            if (mp.count(nums[i])) next[i] = mp[nums[i]];
            mp[nums[i]] = i;
        }

        vector<int> res;
        for (int q : queries) {
            int idx = n + q;
            int d1 = prev[idx] == -1 ? n : idx - prev[idx];
            int d2 = next[q] == -1 ? n : next[q] - q;
            res.push_back(d1 == n && d2 == n ? -1 : min(d1, d2));
        }
        return res;
    }
};
