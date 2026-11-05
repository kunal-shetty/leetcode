// 1385. Find the Distance Value Between Two Arrays
// Difficulty: Easy
// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
// Runtime: 2 ms (beats 37.0%)
// Memory: 16.5 MB (beats 75.8%)
// Submitted: 2026-11-05

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int res = 0;

        for (int num : arr1)
            res += upper_bound(arr2.begin(), arr2.end(), num + d) ==
                   lower_bound(arr2.begin(), arr2.end(), num - d);

        return res;
    }
};
