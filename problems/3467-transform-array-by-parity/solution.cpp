// 3467. Transform Array by Parity
// Difficulty: Easy
// https://leetcode.com/problems/transform-array-by-parity/
// Runtime: 1 ms (beats —)
// Memory: 28.3 MB (beats —)
// Submitted: 2026-06-06

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> res;
        for(auto num : nums){
            res.push_back(num & 1 ? 1 : 0);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
