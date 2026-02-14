// 1365. How Many Numbers Are Smaller Than the Current Number
// Difficulty: Easy
// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Runtime: 7 ms (beats —)
// Memory: 14.2 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int small = 0;
            for(int j = 0; j < n; j++){
                if(nums[i] > nums[j]) small++;
            }
            res.push_back(small);
        }
        return res;
    }
};
