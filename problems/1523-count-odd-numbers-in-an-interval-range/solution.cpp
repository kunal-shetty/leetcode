// 1523. Count Odd Numbers in an Interval Range
// Difficulty: Easy
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Runtime: 2039 ms (beats —)
// Memory: 7.9 MB (beats —)
// Submitted: 2025-12-07

class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++) {
            if(i % 2 == 1) count++;
        }
       return count;
    }
};
