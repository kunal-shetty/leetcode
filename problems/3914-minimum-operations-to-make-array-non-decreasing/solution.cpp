// 3914. Minimum Operations to Make Array Non Decreasing
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing/
// Runtime: 4 ms (beats —)
// Memory: 136.8 MB (beats —)
// Submitted: 2026-04-26

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        long long cost = 0;
        long long prevNeed = nums[0];
        long long prevDiff = 0;

        for(int i = 1; i < n; i++){
            long long need = max(prevNeed, (long long)nums[i]);
            long long diff = need - nums[i];

            if(diff > prevDiff){
                cost += (diff - prevDiff);
            }

            prevNeed = need;
            prevDiff = diff;
        }

        return cost;
    }
};
