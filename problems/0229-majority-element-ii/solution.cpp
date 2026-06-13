// 229. Majority Element II
// Difficulty: Medium
// https://leetcode.com/problems/majority-element-ii/
// Runtime: 8 ms (beats —)
// Memory: 26.2 MB (beats —)
// Submitted: 2026-06-13

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(auto num : nums){
            map[num]++;
        }
        vector<int> res;
        for(auto entry : map){
            if(entry.second > n / 3) res.push_back(entry.first);
        }
        return res;
    }
};
