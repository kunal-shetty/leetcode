// 1855. Maximum Distance Between a Pair of Values
// Difficulty: Medium
// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Runtime: 0 ms (beats —)
// Memory: 102.2 MB (beats —)
// Submitted: 2026-04-23

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;
        
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ans = max(ans, j - i);
                j++;
            } else i++;
        }
        
        return ans;
    }
};
