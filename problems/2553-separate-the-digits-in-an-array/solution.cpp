// 2553. Separate the Digits in an Array
// Difficulty: Easy
// https://leetcode.com/problems/separate-the-digits-in-an-array/
// Runtime: 1 ms (beats —)
// Memory: 15.5 MB (beats —)
// Submitted: 2026-05-11

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s = "";
        vector<int> res;
        for(int num : nums){
            s += to_string(num);
        }
        for(char c : s){
            res.push_back(c - '0');
        }
        return res;
    }
};
