// 2033. Minimum Operations to Make a Uni-Value Grid
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
// Runtime: 61 ms (beats —)
// Memory: 99.9 MB (beats —)
// Submitted: 2026-04-28

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto row : grid) {
            for (int val : row) {
                arr.push_back(val);
            }
        }
        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];
        int ops = 0;
        for (int num : arr) {
            int diff = abs(num - median);
            if (diff % x != 0)
                return -1;
            ops += diff / x;
        }

        return ops;
    }
};
