// 3550. Smallest Index With Digit Sum Equal to Index
// Difficulty: Easy
// https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/
// Runtime: 0 ms (beats —)
// Memory: 31 MB (beats —)
// Submitted: 2026-09-24

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0, num = nums[i];
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            if (sum == i)
                return i;
        }
        return -1;
    }
};
