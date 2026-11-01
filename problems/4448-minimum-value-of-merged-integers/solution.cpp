// 4448. minimum value of merged integers
// Difficulty: Unknown
// https://leetcode.com/problems/minimum-value-of-merged-integers/
// Runtime: 0 ms (beats 100.0%)
// Memory: 32.3 MB (beats 42.7%)
// Submitted: 2026-11-01

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 1; i < nums.size(); i+=2){
            string curr = to_string(nums[i - 1]) + to_string(nums[i]);
            int val = stoi(curr);
            res = min(res, val);
        }
        return res;
    }
};
