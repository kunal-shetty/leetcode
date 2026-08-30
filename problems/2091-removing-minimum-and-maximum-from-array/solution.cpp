// 2091. Removing Minimum and Maximum From Array
// Difficulty: Medium
// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Runtime: 0 ms (beats —)
// Memory: 92.2 MB (beats —)
// Submitted: 2026-08-30

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;
            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int front = max(minIdx, maxIdx) + 1;
        int back = n - min(minIdx, maxIdx);
        int both = min(minIdx + 1 + n - maxIdx, maxIdx + 1 + n - minIdx);

        return min({front, back, both});
    }
};
