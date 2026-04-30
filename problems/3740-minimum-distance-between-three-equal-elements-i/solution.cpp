// 3740. Minimum Distance Between Three Equal Elements I
// Difficulty: Easy
// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
// Runtime: 7 ms (beats —)
// Memory: 28.8 MB (beats —)
// Submitted: 2026-04-30

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minDist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        int dist = 2 * (k - i);
                        minDist = min(minDist, dist);
                    }
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
