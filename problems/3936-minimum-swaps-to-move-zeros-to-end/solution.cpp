// 3936. Minimum Swaps to Move Zeros to End
// Difficulty: Easy
// https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/
// Runtime: 0 ms (beats —)
// Memory: 31.7 MB (beats —)
// Submitted: 2026-05-23

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count = 0;
        int correct = 0;
        int n = nums.size();
        for (int num : nums) {
            if (num == 0)
                count++;
        }
        for (int i = n - count; i < n; i++) {
            if (nums[i] == 0)
                correct++;
        }
        return count - correct;
    }
};
