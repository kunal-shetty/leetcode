// 1979. Find Greatest Common Divisor of Array
// Difficulty: Easy
// https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Runtime: 0 ms (beats —)
// Memory: 16.2 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for(auto num : nums){
            minVal = min(num, minVal);
            maxVal = max(num, maxVal);
        }
        return gcd(minVal, maxVal);
    }
};
