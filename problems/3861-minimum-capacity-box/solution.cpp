// 3861. Minimum Capacity Box
// Difficulty: Easy
// https://leetcode.com/problems/minimum-capacity-box/
// Runtime: 0 ms (beats —)
// Memory: 23.4 MB (beats —)
// Submitted: 2026-04-11

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int idx = -1;
        int minimum = INT_MAX;
        for (int i = 0; i < capacity.size(); i++) {
            if (capacity[i] >= itemSize && capacity[i] < minimum) {
                minimum = capacity[i];
                idx = i;
            }
        }
        return idx;
    }
};
