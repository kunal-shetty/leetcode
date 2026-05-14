// 2784. Check if Array is Good
// Difficulty: Easy
// https://leetcode.com/problems/check-if-array-is-good/
// Runtime: 0 ms (beats —)
// Memory: 26.9 MB (beats —)
// Submitted: 2026-05-14

class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> ilyayushi;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxVal = nums[n - 1];
        for(int i = 1; i <= maxVal; i++){
            ilyayushi.push_back(i);
        }
        ilyayushi.push_back(maxVal);
        if(n != ilyayushi.size()) return false;
        for(int i = 0; i < n; i++){
            if(nums[i] != ilyayushi[i]) return false;
        }
        return true;
    }
};
