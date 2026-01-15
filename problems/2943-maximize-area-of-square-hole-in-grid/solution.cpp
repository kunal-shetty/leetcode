// 2943. Maximize Area of Square Hole in Grid
// Difficulty: Medium
// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
// Runtime: 0 ms (beats —)
// Memory: 31.9 MB (beats —)
// Submitted: 2026-01-15

class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    int longest = 1;
    int current = 1;

    for (int i = 1; i < nums.size(); i++) {

        if (nums[i] == nums[i - 1] + 1) {
            current++;
        }
        else {
            longest = max(longest, current);
            current = 1;
        }
    }

    longest = max(longest, current);
    return longest;
}

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int res = longestConsecutive(hBars) > longestConsecutive(vBars) ? longestConsecutive(vBars) + 1 : longestConsecutive(hBars) + 1;
        return res * res;
    }
};
