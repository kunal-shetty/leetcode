// 4325. minimum operations to sort with locked indices
// Difficulty: Unknown
// https://leetcode.com/problems/minimum-operations-to-sort-with-locked-indices/
// Runtime: 25 ms (beats 57.1%)
// Memory: 45.3 MB (beats 100.0%)
// Submitted: 2026-11-01

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n  = nums.size();
        vector<bool> vis(n, false), need(n, false);
        for(int i = 0; i < n;i ++){
            if(vis[i]) continue;
            int j = i, len = 0;
            int l = n, r = -1;
            while(!vis[j]){
                vis[j] = true;
                l = min(l, j);
                r = max(r, j);
                len++;
                j = nums[j] - 1;
                
            }

            if(len > 1){
                for(int m = l; m <=r; m++){
                    need[m] = true;
            }
                }
            
        }

        int unlocks = 0;
        for(int i = 0;i<n;i++){
            if(need[i] && locked[i]) unlocks++;
        }
        if(unlocks > k) return -1;
        long long swaps = 0;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j <n;j++){
                if(nums[i] > nums[j]) swaps++;
            }
        }
        return swaps + unlocks;
    }
};
