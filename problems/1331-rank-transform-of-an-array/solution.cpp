// 1331. Rank Transform of an Array
// Difficulty: Easy
// https://leetcode.com/problems/rank-transform-of-an-array/
// Runtime: 76 ms (beats —)
// Memory: 50.7 MB (beats —)
// Submitted: 2026-07-12

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> numToRank;      
        set<int> nums(arr.begin(), arr.end());
        int rank = 1;
        for (auto num : nums) {
            numToRank[num] = rank;
            rank++;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numToRank[arr[i]];
        }
        return arr;
    }
};
