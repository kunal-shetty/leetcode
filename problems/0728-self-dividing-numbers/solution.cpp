// 728. Self Dividing Numbers
// Difficulty: Easy
// https://leetcode.com/problems/self-dividing-numbers/
// Runtime: 0 ms (beats —)
// Memory: 9.1 MB (beats —)
// Submitted: 2026-01-04

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> nums;

        for (int i = left; i <= right; i++) {
            int temp = i;
            bool isValid = true;

            while (temp != 0) {
                int digit = temp % 10;

                if (digit == 0 || i % digit != 0) {
                    isValid = false;
                    break;
                }

                temp /= 10;
            }

            if (isValid) {
                nums.push_back(i);
            }
        }

        return nums;
    }
};
