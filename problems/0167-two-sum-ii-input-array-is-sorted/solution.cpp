// 167. Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Runtime: 0 ms (beats —)
// Memory: 19.5 MB (beats —)
// Submitted: 2026-09-03

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left + 1, right + 1};

            if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};
