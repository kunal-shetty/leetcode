// 3689. Maximum Total Subarray Value I
// Difficulty: Medium
// https://leetcode.com/problems/maximum-total-subarray-value-i/
// Runtime: 0 ms (beats —)
// Memory: 103.6 MB (beats —)
// Submitted: 2026-06-09

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxVal = INT_MIN;
        long long minVal = INT_MAX;
        for(auto num : nums){
            if(num > maxVal) maxVal = num;
            if(num < minVal) minVal = num;
        }
        return (maxVal - minVal) * k;
    }
};
