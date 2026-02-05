// 3379. Transformed Array
// Difficulty: Easy
// https://leetcode.com/problems/transformed-array/
// Runtime: 3 ms (beats —)
// Memory: 25.7 MB (beats —)
// Submitted: 2026-02-05

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> result(n);
        for(int i = 0; i < n; i ++){
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return result;
    }
};
