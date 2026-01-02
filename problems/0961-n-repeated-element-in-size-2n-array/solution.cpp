// 961. N-Repeated Element in Size 2N Array
// Difficulty: Easy
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
// Runtime: 3 ms (beats —)
// Memory: 28.4 MB (beats —)
// Submitted: 2026-01-02

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] == nums[i + 1]) && i < nums.size() - 1)
                return nums[i];
        }
        return -1;
    }
};
