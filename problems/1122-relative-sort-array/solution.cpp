// 1122. Relative Sort Array
// Difficulty: Easy
// https://leetcode.com/problems/relative-sort-array/
// Runtime: 0 ms (beats —)
// Memory: 11.1 MB (beats —)
// Submitted: 2026-06-14

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);

        for (int x : arr1)
            freq[x]++;

        vector<int> ans;

        for (int x : arr2) {
            while (freq[x]--) {
                ans.push_back(x);
            }
        }

        for (int i = 0; i <= 1000; i++) {
            while (freq[i] > 0) {
                ans.push_back(i);
                freq[i]--;
            }
        }

        return ans;
    }
};
