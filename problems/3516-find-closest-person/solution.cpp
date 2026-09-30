// 3516. Find Closest Person
// Difficulty: Easy
// https://leetcode.com/problems/find-closest-person/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-09-30

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if (abs(x - z) < abs(y - z))
            return 1;
        if (abs(x - z) > abs(y - z))
            return 2;
        return 0;
    }
};
