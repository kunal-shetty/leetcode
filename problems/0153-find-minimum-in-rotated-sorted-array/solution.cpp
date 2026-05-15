// 153. Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Runtime: 0 ms (beats —)
// Memory: 14.2 MB (beats —)
// Submitted: 2026-05-15

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if (arr[0] < arr[n - 1])
            return arr[0];

        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[0] <= arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return arr[start % n];
    }
};
