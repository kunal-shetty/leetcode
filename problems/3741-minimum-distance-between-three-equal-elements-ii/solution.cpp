// 3741. Minimum Distance Between Three Equal Elements II
// Difficulty: Medium
// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/
// Runtime: 20 ms (beats —)
// Memory: 225.3 MB (beats —)
// Submitted: 2026-04-11

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(n + 1, -1);
        vector<int> second(n + 1, -1);
        int min_dist = INT_MAX;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (second[num] != -1) {
                int dist = i - second[num];
                if (dist < min_dist) {
                    min_dist = dist;
                }
            }
            second[num] = last[num];
            last[num] = i;
        }

        return (min_dist == INT_MAX) ? -1 : 2 * min_dist;
    }
};
