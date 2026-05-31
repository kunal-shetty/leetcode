// 3945. Digit Frequency Score
// Difficulty: Easy
// https://leetcode.com/problems/digit-frequency-score/
// Runtime: 4 ms (beats —)
// Memory: 9.2 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    int digitFrequencyScore(int n) {
        int res = 0;
        unordered_map<int, int> map;
        while (n) {
            int rem = n % 10;
            map[rem]++;
            n /= 10;
        }
        for (auto m : map) {
            res += m.first * m.second;
        }
        return res;
    }
};
