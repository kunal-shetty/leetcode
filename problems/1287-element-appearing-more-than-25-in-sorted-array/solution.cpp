// 1287. Element Appearing More Than 25% In Sorted Array
// Difficulty: Easy
// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Runtime: 0 ms (beats —)
// Memory: 16.2 MB (beats —)
// Submitted: 2026-10-02

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int size = arr.size() / 4;
        for (int i = 0; i < arr.size() - size; i++) {
            if (arr[i] == arr[i + size]) {
                return arr[i];
            }
        }
        return 22;
    }
};
