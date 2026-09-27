// 4067. Longest Subarray With Restricted Pair Sums
// Difficulty: Medium
// https://leetcode.com/problems/longest-subarray-with-restricted-pair-sums/
// Runtime: 1353 ms (beats —)
// Memory: 157.8 MB (beats —)
// Submitted: 2026-09-27

class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size(), res = 1;
        for (int i = 0; i < n; i++) {
            vector<int> cnt(501), vals;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                bool ok = true;
                for (auto k : vals) {
                    if (k < x) {
                        int y = x - k;
                        if (y <= 500 && (k == y ? cnt[k] > 1 : cnt[y]))
                            ok = false;
                    }
                    if (ok && k + x <= 500 && cnt[k + x])
                        ok = false;
                    if (!ok)
                        break;
                }
                if (!ok)
                    break;
                if (!cnt[x])
                    vals.push_back(x);
                cnt[x]++;
                res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
