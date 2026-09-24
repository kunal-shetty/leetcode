// 1431. Kids With the Greatest Number of Candies
// Difficulty: Easy
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Runtime: 0 ms (beats —)
// Memory: 12.3 MB (beats —)
// Submitted: 2026-09-24

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxVal = INT_MIN;
        for(auto candy : candies){
            maxVal = max(candy, maxVal);
        }
        for(auto candy : candies){
            if(candy + extraCandies >= maxVal) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
