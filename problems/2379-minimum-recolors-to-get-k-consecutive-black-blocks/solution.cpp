// 2379. Minimum Recolors to Get K Consecutive Black Blocks
// Difficulty: Easy
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-07-23

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int maxCount = 0;

        for (int i = 0; i <= blocks.length() - k; i++) {
            string sub = blocks.substr(i, k);
            int c = count(sub.begin(), sub.end(), 'B');
            maxCount = max(maxCount, c);
        }

        return k - maxCount;
    }
};
