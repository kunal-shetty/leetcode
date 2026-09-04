// 2653. Sliding Subarray Beauty
// Difficulty: Medium
// https://leetcode.com/problems/sliding-subarray-beauty/
// Runtime: 215 ms (beats —)
// Memory: 191.4 MB (beats —)
// Submitted: 2026-09-04

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> res;
        map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;
            if (i >= k - 1) {
                if (i >= k)
                    map[nums[i - k]]--;
                int sum = 0, t = 0;
                for (auto entry : map) {
                    sum += entry.second;
                    if (sum >= x) {
                        t = (entry.first < 0) ? entry.first : 0;
                        break;
                    }
                }
                res.push_back(t);
            }
        }
        return res;
    }
};
