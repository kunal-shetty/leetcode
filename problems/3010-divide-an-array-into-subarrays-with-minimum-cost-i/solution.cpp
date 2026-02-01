// 3010. Divide an Array Into Subarrays With Minimum Cost I
// Difficulty: Easy
// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
// Runtime: 0 ms (beats —)
// Memory: 30.6 MB (beats —)
// Submitted: 2026-02-01

class Solution {
public:
    int minimumCost(vector<int>& nums) {
    int firstMin = INT_MAX;
    int secondMin = INT_MAX;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < firstMin) {
            secondMin = firstMin;
            firstMin = nums[i];
        } else if (nums[i] < secondMin) {
            secondMin = nums[i];
        }
    }
    return nums[0] + firstMin + secondMin;
}

};
