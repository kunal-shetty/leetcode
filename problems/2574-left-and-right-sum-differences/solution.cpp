// 2574. Left and Right Sum Differences
// Difficulty: Easy
// https://leetcode.com/problems/left-and-right-sum-differences/
// Runtime: 0 ms (beats —)
// Memory: 15.4 MB (beats —)
// Submitted: 2026-06-06

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n), rightSum(n);
        for(int i = 1; i < n; i++){
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back(abs(leftSum[i] - rightSum[i]));
        }
        return res;
    }
};
