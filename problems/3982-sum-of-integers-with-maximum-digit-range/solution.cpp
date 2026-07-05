// 3982. Sum of Integers with Maximum Digit Range
// Difficulty: Easy
// https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/
// Runtime: 3 ms (beats —)
// Memory: 30.9 MB (beats —)
// Submitted: 2026-07-05

class Solution {
public:
    int digitRange(int n) {
        int maxD = 0, minD = 9;
        while (n > 0) {
            int d = n % 10;
            maxD = max(d, maxD);
            minD = min(d, minD);
            n /= 10;
        }
        return maxD - minD;
    }
    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;
        for (auto num : nums) {
            maxRange = max(maxRange, digitRange(num));
        }
        int sum = 0;
        for (auto num : nums) {
            if (digitRange(num) == maxRange) {
                sum += num;
            }
        }
        return sum;
    }
};
