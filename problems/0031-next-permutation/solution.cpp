// 31. Next Permutation
// Difficulty: Medium
// https://leetcode.com/problems/next-permutation/
// Runtime: 0 ms (beats —)
// Memory: 15.8 MB (beats —)
// Submitted: 2026-09-17

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int b = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                b = i;
                break;
            }
        }

        if (b != -1) {
            for (int i = n - 1; i > b; i--) {
                if (nums[i] > nums[b]) {
                    swap(nums[b], nums[i]);
                    break;
                }
            }
        }

        reverse(nums.begin() + b + 1, nums.end());
    }
};
