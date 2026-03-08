// 1980. Find Unique Binary String
// Difficulty: Medium
// https://leetcode.com/problems/find-unique-binary-string/
// Runtime: 2 ms (beats —)
// Memory: 12.4 MB (beats —)
// Submitted: 2026-03-08

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            if (nums[i][i] == '0') res += '1';
            else res += '0';
        }
        return res;
    }
};
