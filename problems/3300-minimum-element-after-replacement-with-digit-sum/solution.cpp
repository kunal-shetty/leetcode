// 3300. Minimum Element After Replacement With Digit Sum
// Difficulty: Easy
// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
// Runtime: 1 ms (beats —)
// Memory: 27.8 MB (beats —)
// Submitted: 2026-05-29

class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;
        for(int num : nums){
            int sum = 0;
            while(num){
                sum += num % 10;
                num /= 10;
            }
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};
