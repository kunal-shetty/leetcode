// 4391. count subarrays with loose bounds
// Difficulty: Unknown
// https://leetcode.com/problems/count-subarrays-with-loose-bounds/
// Runtime: 10 ms (beats 100.0%)
// Memory: 312.8 MB (beats 100.0%)
// Submitted: 2026-10-24

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long  c = 0, s = 0;
        for(auto num : nums){
            
            if(num < minK || num > maxK){
            c += (s * (s + 1) / 2);
                s=0;
            }
            else s++;
        }
        c += (s * (s + 1) / 2);
        return c;
    }
};
