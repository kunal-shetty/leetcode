// 27. Remove Element
// Difficulty: Easy
// https://leetcode.com/problems/remove-element/
// Runtime: 0 ms (beats —)
// Memory: 11.8 MB (beats —)
// Submitted: 2026-04-01

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == val) {
                n--; 
                nums[i] = -1;
            }
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return n;
    }
};
