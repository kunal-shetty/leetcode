// 1512. Number of Good Pairs
// Difficulty: Easy
// https://leetcode.com/problems/number-of-good-pairs/
// Runtime: 0 ms (beats —)
// Memory: 9.8 MB (beats —)
// Submitted: 2026-08-11

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
            for(int i = 0; i < nums.size(); i++)
            {            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]) count++;
            }
        }
        return count;
    }
};
