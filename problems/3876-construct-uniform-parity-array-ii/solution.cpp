// 3876. Construct Uniform Parity Array II
// Difficulty: Medium
// https://leetcode.com/problems/construct-uniform-parity-array-ii/
// Runtime: 0 ms (beats —)
// Memory: 165.7 MB (beats —)
// Submitted: 2026-09-03

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = INT_MAX;

        for(int num : nums1) {
            minVal = min(minVal, num);
        }

        if(minVal & 1) {
            return true;
        }

        for(int num : nums1) {
            if(num & 1) {
                return false;
            }
        }

        return true;
    }
};
