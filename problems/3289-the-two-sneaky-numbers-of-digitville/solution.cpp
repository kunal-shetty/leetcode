// 3289. The Two Sneaky Numbers of Digitville
// Difficulty: Easy
// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
// Runtime: 2 ms (beats —)
// Memory: 26.4 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> count;
        for(auto num : nums){
            count[num]++;
        }
        vector<int> res;
        for(auto entry : count){
            if(entry.second > 1) res.push_back(entry.first);
        }
        return res;
    }
};
