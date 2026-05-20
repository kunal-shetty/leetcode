// 905. Sort Array By Parity
// Difficulty: Easy
// https://leetcode.com/problems/sort-array-by-parity/
// Runtime: 3 ms (beats —)
// Memory: 21.5 MB (beats —)
// Submitted: 2026-05-20

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        for(int num : nums){
            if(num & 1) odd.push_back(num);
            else even.push_back(num);
        }
        vector<int> res;
        for(auto num : even) res.push_back(num);
        for(auto num : odd) res.push_back(num);
        return res;
    }
};
