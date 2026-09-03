// 11. Container With Most Water
// Difficulty: Medium
// https://leetcode.com/problems/container-with-most-water/
// Runtime: 4 ms (beats —)
// Memory: 63 MB (beats —)
// Submitted: 2026-09-03

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = INT_MIN;
        int L = 0, R= height.size() - 1;
        while(L < R){
            int high = min(height[L], height[R]);
            int dist = (R - L);
            maxWater = max(maxWater, dist * high);
            if(height[L] < height[R]) L++; else R--;
        }
        return maxWater;
    }
};
