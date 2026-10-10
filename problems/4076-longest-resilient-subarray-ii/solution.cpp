// 4076. Longest Resilient Subarray II
// Difficulty: Medium
// https://leetcode.com/problems/longest-resilient-subarray-ii/
// Runtime: 12 ms (beats —)
// Memory: 187.9 MB (beats —)
// Submitted: 2026-10-10

class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int res = 1, curr = 1;
        int n = nums.size();
        for(int i = 0; i <n; ){
            int  j = i;
            int r = nums[i] % k;

            while(j < n && nums[j] % k == r) j++;
            int l = j - i;
            int need = k / gcd(k,r);
            
           res = max(res, (l - 1) / need * need + 1);
          
             i =j;
        //     if(nums[i] % k == nums[i - 1] % k) curr++;
        //     else curr = 1;

        //     res = max(curr, res);
        }
        return res;
    }
};
