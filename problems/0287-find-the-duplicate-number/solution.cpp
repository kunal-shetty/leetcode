// 287. Find the Duplicate Number
// Difficulty: Medium
// https://leetcode.com/problems/find-the-duplicate-number/
// Runtime: 4 ms (beats —)
// Memory: 65.1 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
