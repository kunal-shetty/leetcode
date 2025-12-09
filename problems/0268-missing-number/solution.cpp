// 268. Missing Number
// Difficulty: Easy
// https://leetcode.com/problems/missing-number/
// Runtime: 4 ms (beats —)
// Memory: 21.8 MB (beats —)
// Submitted: 2025-12-09

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(num != nums[i]) return num;
            num++;
        }
        return num;
    }
};
