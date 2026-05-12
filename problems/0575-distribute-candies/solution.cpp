// 575. Distribute Candies
// Difficulty: Easy
// https://leetcode.com/problems/distribute-candies/
// Runtime: 108 ms (beats —)
// Memory: 120.1 MB (beats —)
// Submitted: 2026-10-01

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
       unordered_set<int> candy(candyType.begin(),  candyType.end());
        return min(candyType.size() / 2, candy.size());
    }
};
