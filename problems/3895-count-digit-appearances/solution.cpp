// 3895. Count Digit Appearances
// Difficulty: Medium
// https://leetcode.com/problems/count-digit-appearances/
// Runtime: 5 ms (beats —)
// Memory: 36.9 MB (beats —)
// Submitted: 2026-04-30

class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(auto num : nums){
            while(num > 0){
                if(num % 10 == digit) count++;
                num /= 10; 
            }
        }
        return count;
    }
};
