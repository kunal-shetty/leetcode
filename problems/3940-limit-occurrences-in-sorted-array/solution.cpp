// 3940. Limit Occurrences in Sorted Array
// Difficulty: Easy
// https://leetcode.com/problems/limit-occurrences-in-sorted-array/
// Runtime: 8 ms (beats —)
// Memory: 33.7 MB (beats —)
// Submitted: 2026-05-24

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> map;
        for (int num : nums) {
            if (map[num] < k) {
                res.push_back(num);
                map[num]++;
            }
        }
        return res;
    }
};
