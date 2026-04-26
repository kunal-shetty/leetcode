// 3912. Valid Elements in an Array
// Difficulty: Easy
// https://leetcode.com/problems/valid-elements-in-an-array/
// Runtime: 0 ms (beats —)
// Memory: 32.6 MB (beats —)
// Submitted: 2026-04-26

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;

        vector<int> leftMax(n, -1), rightMax(n, -1);

        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }

        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], nums[i + 1]);
        }

        vector<int> res;

        for(int i = 0; i < n; i++){
            if(i == 0 || i == n - 1) {
                res.push_back(nums[i]);
            }
            else if(nums[i] > leftMax[i] || nums[i] > rightMax[i]) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};
