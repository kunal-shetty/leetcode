// 3866. First Unique Even Element
// Difficulty: Easy
// https://leetcode.com/problems/first-unique-even-element/
// Runtime: 0 ms (beats —)
// Memory: 28.3 MB (beats —)
// Submitted: 2026-04-11

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                count[nums[i]]++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] == 1) {
                return nums[i];
            }
        }

        return -1;
    }
};
