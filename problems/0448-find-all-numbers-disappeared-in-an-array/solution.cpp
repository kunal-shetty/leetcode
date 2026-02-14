// 448. Find All Numbers Disappeared in an Array
// Difficulty: Easy
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Runtime: 5 ms (beats —)
// Memory: 53.1 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }

        return result;
    }
};
