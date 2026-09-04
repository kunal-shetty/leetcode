// 42. Trapping Rain Water
// Difficulty: Hard
// https://leetcode.com/problems/trapping-rain-water/
// Runtime: 3 ms (beats —)
// Memory: 26.1 MB (beats —)
// Submitted: 2026-09-04

class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int left = height[L], right = height[R];
        int water = 0;
        while(L < R){
            if(height[L] < height[R]){
                left = max(height[L], left);
                water += abs(left - height[L]);
                L++;
            }
            else {
                right = max(height[R], right);
                water += abs(right - height[R]);
                R--;
            }
        }
        return water;
    }
};
