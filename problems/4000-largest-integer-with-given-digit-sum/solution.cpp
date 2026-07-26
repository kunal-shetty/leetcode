// 4000. Largest Integer With Given Digit Sum
// Difficulty: Easy
// https://leetcode.com/problems/largest-integer-with-given-digit-sum/
// Runtime: 35 ms (beats —)
// Memory: 8.3 MB (beats —)
// Submitted: 2026-07-26

class Solution {
public:
    int sum(int num) {
        int s = 0;
        while (num) {
            s += num % 10;
            num /= 10;
        }
        return s;
    }
    int largestInteger(int n, int s) {
        if (s == 0)
            return 0;

        int l = 1;
        for (int i = 0; i < n; i++) {
            l *= 10;
        }

        for (int i = l - 1; i >= 0; i--) {
            if (sum(i) == s)
                return i;
        }
        return -1;
    }
};
