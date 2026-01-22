// 3507. Minimum Pair Removal to Sort Array I
// Difficulty: Easy
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/
// Runtime: 0 ms (beats —)
// Memory: 26.6 MB (beats —)
// Submitted: 2026-01-22

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int index = 0;

            // Find leftmost adjacent pair with minimum sum
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }

            // Merge the pair
            nums[index] += nums[index + 1];
            nums.erase(nums.begin() + index + 1);

            operations++;
        }

        return operations;
    }

private:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
