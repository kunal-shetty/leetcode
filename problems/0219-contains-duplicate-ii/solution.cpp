// 219. Contains Duplicate II
// Difficulty: Easy
// https://leetcode.com/problems/contains-duplicate-ii/
// Runtime: 1785 ms (beats —)
// Memory: 73.9 MB (beats —)
// Submitted: 2026-03-03

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j <= i + k && j < nums.size(); j++){                
                if(nums[i] == nums[j]) return true;
            }
        }
        return false;  
    }
};
