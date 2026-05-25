// 3909. Compare Sums of Bitonic Parts
// Difficulty: Medium
// https://leetcode.com/problems/compare-sums-of-bitonic-parts/
// Runtime: 1 ms (beats —)
// Memory: 125.5 MB (beats —)
// Submitted: 2026-05-25

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int peakIdx = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]) peakIdx = i;
        }
        long long asc = 0, dsc = 0;
        for(int i = 0; i <= peakIdx; i++){
            asc += nums[i];
        }
        for(int i = peakIdx; i < nums.size(); i++){
            dsc += nums[i];
        }
        if(asc > dsc) return 0;
        if(asc < dsc) return 1;
        return -1;
    }
};
