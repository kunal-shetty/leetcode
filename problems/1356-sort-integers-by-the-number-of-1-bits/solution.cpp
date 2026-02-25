// 1356. Sort Integers by The Number of 1 Bits
// Difficulty: Easy
// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Runtime: 17 ms (beats —)
// Memory: 14.3 MB (beats —)
// Submitted: 2026-02-25

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr.size() - 1 - i; j++) {

                int bits1 = __builtin_popcount(arr[j]);
                int bits2 = __builtin_popcount(arr[j + 1]);

                if(bits1 > bits2 || 
                   (bits1 == bits2 && arr[j] > arr[j + 1])) {
                    
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        return arr;
    }
};
