// 1051. Height Checker
// Difficulty: Easy
// https://leetcode.com/problems/height-checker/
// Runtime: 0 ms (beats —)
// Memory: 11.3 MB (beats —)
// Submitted: 2026-08-06

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(),heights.end());
        sort(expected.begin(), expected.end());
        int count = 0;
        for(int i = 0; i < heights.size(); i++){
        if(heights[i] != expected[i]) count++;
        }
        return count;
    }
};
