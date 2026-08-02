// 4011. Count Subarrays With Even Odd Ratio I
// Difficulty: Medium
// https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/
// Runtime: 73 ms (beats —)
// Memory: 32.6 MB (beats —)
// Submitted: 2026-08-02

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> odd(n + 1, 0), even(n + 1, 0);
        vector<long long> pref(n + 1, 0);

        for(int i =0; i < n;i ++){
            odd[i + 1] = odd[i];
            even[i + 1] = even[i];

            if(nums[i] & 1) odd[i + 1]++; 
            else even[i + 1]++;

            pref[i + 1] = 1LL * b * even[i + 1] - 1LL * a * odd[i + 1];
        }
            int ans = 0;

            for(int l = 0; l < n; l++){
                for(int r = l + 1; r <=n; r++){
                    if(odd[r] > odd[l] && pref[r] <= pref[l]) ans++;
                }
            }
        return ans;
    }
};
