// 2161. Partition Array According to Given Pivot
// Difficulty: Medium
// https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Runtime: 8 ms (beats —)
// Memory: 139.5 MB (beats —)
// Submitted: 2026-06-08

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> big;
        int pivotCount = 0;
        for (auto num : nums) {
            if (num < pivot)
                small.push_back(num);
            else if (num > pivot)
                big.push_back(num);
            else
                pivotCount++;
        }
        vector<int> res;
        for (auto s : small)
            res.push_back(s);
        while (pivotCount) {
            res.push_back(pivot);
            pivotCount--;
        }
        for (auto b : big)
            res.push_back(b);

        return res;
    }
};
