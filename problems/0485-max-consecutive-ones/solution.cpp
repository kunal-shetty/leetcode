// 485. Max Consecutive Ones
// Difficulty: Easy
// https://leetcode.com/problems/max-consecutive-ones/
// Runtime: 0 ms (beats —)
// Memory: 50 MB (beats —)
// Submitted: 2026-07-14

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0, c = 0;
        for(auto num : nums){
            if(num == 1) c++;
            else c = 0;
            mx = max(mx, c);
        }
        return mx;
    }
};
