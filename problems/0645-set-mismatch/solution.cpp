// 645. Set Mismatch
// Difficulty: Easy
// https://leetcode.com/problems/set-mismatch/
// Runtime: 0 ms (beats —)
// Memory: 26.4 MB (beats —)
// Submitted: 2026-02-14

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        int duplicate = -1, missing = -1;

        for(int num : nums) {
            freq[num]++;
        }

        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2) duplicate = i;
            if(freq[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};
