// 477. Total Hamming Distance
// Difficulty: Medium
// https://leetcode.com/problems/total-hamming-distance/
// Runtime: 1141 ms (beats —)
// Memory: 22.8 MB (beats —)
// Submitted: 2026-08-07

class Solution {
public:
int hammingDistance(int a, int b){
    return __builtin_popcount(a ^ b);
}
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                res += hammingDistance(nums[i], nums[j]);
            }
        }
        return res;
    }
};
